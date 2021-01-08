#include "correctness.h"
#include <smolrtsp/response.h>

void SmolRTSP_Response_serialize(
    SmolRTSP_Response self, SmolRTSP_UserWriter user_writer, void *user_cx) {
    precondition(user_writer);

    SmolRTSP_ResponseLine_serialize(self.start_line, user_writer, user_cx);
    SmolRTSP_HeaderMap_serialize(self.header_map, user_writer, user_cx);
    user_writer(self.body.len, self.body.ptr, user_cx);
}

bool SmolRTSP_Response_eq(SmolRTSP_Response lhs, SmolRTSP_Response rhs) {
    return SmolRTSP_ResponseLine_eq(lhs.start_line, rhs.start_line) &&
           SmolRTSP_HeaderMap_eq(lhs.header_map, rhs.header_map) &&
           Slice99_primitive_eq(lhs.body, rhs.body);
}
