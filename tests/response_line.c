#include <smolrtsp/response_line.h>

#include "nala/nala.h"

TEST(deserialize_response_line) {
    const SmolRTSP_ResponseLine expected = {
        .version = {.major = 1, .minor = 1},
        .code = SMOLRTSP_STATUS_CODE_OK,
        .reason = Slice99_from_str("OK"),
    };

    SmolRTSP_ResponseLineDeserializerState state = SMOLRTSP_RESPONSE_LINE_DESERIALIZER_STATE_INIT;
    SmolRTSP_ResponseLine result;
    SmolRTSP_DeserializeResult res;

#define CHECK(data, expected_res, expected_state)                                                  \
    res = SmolRTSP_ResponseLine_deserialize(&result, (Slice99[]){Slice99_from_str(data)}, &state); \
    ASSERT_EQ(res, SmolRTSP_DeserializeResult##expected_res);                                      \
    ASSERT_EQ(state.tag, SmolRTSP_ResponseLineDeserializerState##expected_state)

    CHECK("RTSP/1.1 ", Pending, StatusCode);
    assert(SmolRTSP_RTSPVersion_eq(result.version, expected.version));

    CHECK("200 ", Pending, ReasonPhrase);
    assert(result.code == expected.code);

    CHECK("OK\r\n", Ok, Done);
    assert(SmolRTSP_ResponseLine_eq(result, expected));

#undef CHECK
}

TEST(serialize_response_line) {
    char buffer[100] = {0};

    const SmolRTSP_ResponseLine line = {
        .version = SmolRTSP_RTSPVersion_new(1, 0),
        .code = SMOLRTSP_STATUS_CODE_OK,
        .reason = Slice99_from_str("OK"),
    };

    SmolRTSP_ResponseLine_serialize(line, smolrtsp_char_buffer_writer, buffer);

    ASSERT_EQ(strcmp(buffer, "RTSP/1.0 200 OK\r\n"), 0);
}
