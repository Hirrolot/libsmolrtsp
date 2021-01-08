
/**
 * @file
 *  An RTSP request line.
 */

#ifndef SMOLRTSP_REQUEST_LINE_H
#define SMOLRTSP_REQUEST_LINE_H

#include <smolrtsp/method.h>
#include <smolrtsp/request_uri.h>
#include <smolrtsp/rtsp_version.h>

#include <stdbool.h>

/**
 * An RTSP request line.
 */
typedef struct {
    SmolRTSP_Method method;
    SmolRTSP_RequestURI uri;
    SmolRTSP_RTSPVersion version;
} SmolRTSP_RequestLine;

/**
 * Serializes @p self to @p user_writer.
 *
 * @param[in] user_cx Some value provided to @p user_writer on each write.
 *
 * @pre `user_writer != NULL`
 */
void SmolRTSP_RequestLine_serialize(
    SmolRTSP_RequestLine self, SmolRTSP_UserWriter user_writer, void *user_cx);

/**
 * A state in which #SmolRTSP_RequestLineDeserializer is located.
 */
typedef enum {
    SmolRTSP_RequestLineDeserializerStateMethod,
    SmolRTSP_RequestLineDeserializerStateRequestURI,
    SmolRTSP_RequestLineDeserializerStateRTSPVersion,
    SmolRTSP_RequestLineDeserializerStateCRLF,
    SmolRTSP_RequestLineDeserializerStateDone,
} SmolRTSP_RequestLineDeserializerState;

SmolRTSP_DeserializeResult SmolRTSP_RequestLine_deserialize(
    SmolRTSP_RequestLine *restrict self, Slice99 *restrict data,
    SmolRTSP_RequestLineDeserializerState *restrict state);

/**
 * Tests @p lhs and @p rhs for equality.
 *
 * @return `true` if @p lhs and @rhs are equal, `false` otherwise.
 */
bool SmolRTSP_RequestLine_eq(SmolRTSP_RequestLine lhs, SmolRTSP_RequestLine rhs);

#endif // SMOLRTSP_REQUEST_LINE_H
