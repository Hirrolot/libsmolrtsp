/**
 * @file
 *  An RTSP status code.
 */

#ifndef SMOLRTSP_STATUS_CODE_H
#define SMOLRTSP_STATUS_CODE_H

#include <smolrtsp/deserialization.h>
#include <smolrtsp/user_writer.h>

#include <stdint.h>

#include <slice99.h>

/**
 * An RTSP status code.
 */
typedef uint_least16_t SmolRTSP_StatusCode;

#define SMOLRTSP_STATUS_CODE_CONTINUE                               100
#define SMOLRTSP_STATUS_CODE_OK                                     200
#define SMOLRTSP_STATUS_LOW_ON_STORAGE_SPACE                        250
#define SMOLRTSP_STATUS_CODE_MOVED_PERMANENTLY                      301
#define SMOLRTSP_STATUS_CODE_FOUND                                  302
#define SMOLRTSP_STATUS_CODE_SEE_OTHER                              303
#define SMOLRTSP_STATUS_CODE_NOT_MODIFIED                           304
#define SMOLRTSP_STATUS_CODE_USE_PROXY                              305
#define SMOLRTSP_STATUS_CODE_BAD_REQUEST                            400
#define SMOLRTSP_STATUS_CODE_UNAUTHORIZED                           401
#define SMOLRTSP_STATUS_CODE_PAYMENT_REQUIRED                       402
#define SMOLRTSP_STATUS_CODE_FORBIDDEN                              403
#define SMOLRTSP_STATUS_CODE_NOT_FOUND                              404
#define SMOLRTSP_STATUS_CODE_METHOD_NOT_ALLOWED                     405
#define SMOLRTSP_STATUS_CODE_NOT_ACCEPTABLE                         406
#define SMOLRTSP_STATUS_CODE_PROXY_AUTHENTICATION_REQUIRED          407
#define SMOLRTSP_STATUS_CODE_REQUEST_TIMEOUT                        408
#define SMOLRTSP_STATUS_CODE_GONE                                   410
#define SMOLRTSP_STATUS_CODE_PRECONDITION_FAILED                    412
#define SMOLRTSP_STATUS_CODE_REQUEST_MESSAGE_BODY_TOO_LARGE         413
#define SMOLRTSP_STATUS_CODE_REQUEST_URI_TOO_LONG                   414
#define SMOLRTSP_STATUS_CODE_UNSUPPORTED_MEDIA_TYPE                 415
#define SMOLRTSP_STATUS_CODE_PARAMETER_NOT_UNDERSTOOD               451
#define SMOLRTSP_STATUS_CODE_RESERVED                               452
#define SMOLRTSP_STATUS_CODE_NOT_ENOUGH_BANDWIDTH                   453
#define SMOLRTSP_STATUS_CODE_SESSION_NOT_FOUND                      454
#define SMOLRTSP_STATUS_CODE_METHOD_NOT_VALID_IN_THIS_STATE         455
#define SMOLRTSP_STATUS_CODE_HEADER_FIELD_NOT_VALID_FOR_RESOURCE    456
#define SMOLRTSP_STATUS_CODE_INVALID_RANGE                          457
#define SMOLRTSP_STATUS_CODE_PARAMETER_IS_READ_ONLY                 458
#define SMOLRTSP_STATUS_CODE_AGGREGATE_OPERATION_NOT_ALLOWED        459
#define SMOLRTSP_STATUS_CODE_ONLY_AGGREGATE_OPERATION_ALLOWED       460
#define SMOLRTSP_STATUS_CODE_UNSUPPORTED_TRANSPORT                  461
#define SMOLRTSP_STATUS_CODE_DESTINATION_UNREACHABLE                462
#define SMOLRTSP_STATUS_CODE_DESTINATION_PROHIBITED                 463
#define SMOLRTSP_STATUS_CODE_DATA_TRANSPORT_NOT_READY_YET           464
#define SMOLRTSP_STATUS_CODE_NOTIFICATION_REASON_UNKNOWN            465
#define SMOLRTSP_STATUS_CODE_KEY_MANAGEMENT_ERROR                   466
#define SMOLRTSP_STATUS_CODE_CONNECTION_AUTHORIZATION_REQUIRED      470
#define SMOLRTSP_STATUS_CODE_CONNECTION_CREDENTIALS_NOT_ACCEPTED    471
#define SMOLRTSP_STATUS_CODE_FAILURE_TO_ESTABLISH_SECURE_CONNECTION 472
#define SMOLRTSP_STATUS_CODE_INTERNAL_SERVER_ERROR                  500
#define SMOLRTSP_STATUS_CODE_NOT_IMPLEMENTED                        501
#define SMOLRTSP_STATUS_CODE_BAD_GATEWAY                            502
#define SMOLRTSP_STATUS_CODE_SERVICE_UNAVAILABLE                    503
#define SMOLRTSP_STATUS_CODE_GATEWAY_TIMEOUT                        504
#define SMOLRTSP_STATUS_CODE_RTSP_VERSION_NOT_SUPPORTED             505
#define SMOLRTSP_STATUS_CODE_OPTION_NOT_SUPPORTED                   551
#define SMOLRTSP_STATUS_CODE_PROXY_UNAVAILABLE                      553

/**
 * Serializes @p self to @p user_writer.
 *
 * @param[in] user_cx Some value provided to @p user_writer on each write.
 *
 * @pre `user_writer != NULL`
 */
void SmolRTSP_StatusCode_serialize(
    SmolRTSP_StatusCode self, SmolRTSP_UserWriter user_writer, void *user_cx);

SmolRTSP_DeserializeResult
SmolRTSP_StatusCode_deserialize(SmolRTSP_StatusCode *restrict self, Slice99 *restrict data);

#endif // SMOLRTSP_STATUS_CODE_H
