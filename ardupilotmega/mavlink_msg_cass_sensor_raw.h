#pragma once
// MESSAGE CASS_SENSOR_RAW PACKING

#define MAVLINK_MSG_ID_CASS_SENSOR_RAW 227


typedef struct __mavlink_cass_sensor_raw_t {
 uint32_t time_boot_ms; /*<  Timestamp (milliseconds since system boot)*/
 float values[5]; /*<  Raw data*/
 uint8_t app_datatype; /*<  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data*/
 uint8_t app_datalength; /*<  Length of raw data array*/
} mavlink_cass_sensor_raw_t;

#define MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN 26
#define MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN 26
#define MAVLINK_MSG_ID_227_LEN 26
#define MAVLINK_MSG_ID_227_MIN_LEN 26

#define MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC 237
#define MAVLINK_MSG_ID_227_CRC 237

#define MAVLINK_MSG_CASS_SENSOR_RAW_FIELD_VALUES_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CASS_SENSOR_RAW { \
    227, \
    "CASS_SENSOR_RAW", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_cass_sensor_raw_t, time_boot_ms) }, \
         { "app_datatype", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_cass_sensor_raw_t, app_datatype) }, \
         { "app_datalength", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_cass_sensor_raw_t, app_datalength) }, \
         { "values", NULL, MAVLINK_TYPE_FLOAT, 5, 4, offsetof(mavlink_cass_sensor_raw_t, values) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CASS_SENSOR_RAW { \
    "CASS_SENSOR_RAW", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_cass_sensor_raw_t, time_boot_ms) }, \
         { "app_datatype", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_cass_sensor_raw_t, app_datatype) }, \
         { "app_datalength", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_cass_sensor_raw_t, app_datalength) }, \
         { "values", NULL, MAVLINK_TYPE_FLOAT, 5, 4, offsetof(mavlink_cass_sensor_raw_t, values) }, \
         } \
}
#endif

/**
 * @brief Pack a cass_sensor_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Timestamp (milliseconds since system boot)
 * @param app_datatype  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data
 * @param app_datalength  Length of raw data array
 * @param values  Raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cass_sensor_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t app_datatype, uint8_t app_datalength, const float *values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 24, app_datatype);
    _mav_put_uint8_t(buf, 25, app_datalength);
    _mav_put_float_array(buf, 4, values, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN);
#else
    mavlink_cass_sensor_raw_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.app_datatype = app_datatype;
    packet.app_datalength = app_datalength;
    mav_array_memcpy(packet.values, values, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CASS_SENSOR_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
}

/**
 * @brief Pack a cass_sensor_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Timestamp (milliseconds since system boot)
 * @param app_datatype  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data
 * @param app_datalength  Length of raw data array
 * @param values  Raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cass_sensor_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t app_datatype,uint8_t app_datalength,const float *values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 24, app_datatype);
    _mav_put_uint8_t(buf, 25, app_datalength);
    _mav_put_float_array(buf, 4, values, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN);
#else
    mavlink_cass_sensor_raw_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.app_datatype = app_datatype;
    packet.app_datalength = app_datalength;
    mav_array_memcpy(packet.values, values, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CASS_SENSOR_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
}

/**
 * @brief Encode a cass_sensor_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cass_sensor_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cass_sensor_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cass_sensor_raw_t* cass_sensor_raw)
{
    return mavlink_msg_cass_sensor_raw_pack(system_id, component_id, msg, cass_sensor_raw->time_boot_ms, cass_sensor_raw->app_datatype, cass_sensor_raw->app_datalength, cass_sensor_raw->values);
}

/**
 * @brief Encode a cass_sensor_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cass_sensor_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cass_sensor_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cass_sensor_raw_t* cass_sensor_raw)
{
    return mavlink_msg_cass_sensor_raw_pack_chan(system_id, component_id, chan, msg, cass_sensor_raw->time_boot_ms, cass_sensor_raw->app_datatype, cass_sensor_raw->app_datalength, cass_sensor_raw->values);
}

/**
 * @brief Send a cass_sensor_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Timestamp (milliseconds since system boot)
 * @param app_datatype  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data
 * @param app_datalength  Length of raw data array
 * @param values  Raw data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cass_sensor_raw_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint8_t app_datatype, uint8_t app_datalength, const float *values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 24, app_datatype);
    _mav_put_uint8_t(buf, 25, app_datalength);
    _mav_put_float_array(buf, 4, values, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW, buf, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
#else
    mavlink_cass_sensor_raw_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.app_datatype = app_datatype;
    packet.app_datalength = app_datalength;
    mav_array_memcpy(packet.values, values, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW, (const char *)&packet, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
#endif
}

/**
 * @brief Send a cass_sensor_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cass_sensor_raw_send_struct(mavlink_channel_t chan, const mavlink_cass_sensor_raw_t* cass_sensor_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cass_sensor_raw_send(chan, cass_sensor_raw->time_boot_ms, cass_sensor_raw->app_datatype, cass_sensor_raw->app_datalength, cass_sensor_raw->values);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW, (const char *)cass_sensor_raw, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cass_sensor_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint8_t app_datatype, uint8_t app_datalength, const float *values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint8_t(buf, 24, app_datatype);
    _mav_put_uint8_t(buf, 25, app_datalength);
    _mav_put_float_array(buf, 4, values, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW, buf, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
#else
    mavlink_cass_sensor_raw_t *packet = (mavlink_cass_sensor_raw_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->app_datatype = app_datatype;
    packet->app_datalength = app_datalength;
    mav_array_memcpy(packet->values, values, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASS_SENSOR_RAW, (const char *)packet, MAVLINK_MSG_ID_CASS_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN, MAVLINK_MSG_ID_CASS_SENSOR_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE CASS_SENSOR_RAW UNPACKING


/**
 * @brief Get field time_boot_ms from cass_sensor_raw message
 *
 * @return  Timestamp (milliseconds since system boot)
 */
static inline uint32_t mavlink_msg_cass_sensor_raw_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field app_datatype from cass_sensor_raw message
 *
 * @return  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data
 */
static inline uint8_t mavlink_msg_cass_sensor_raw_get_app_datatype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field app_datalength from cass_sensor_raw message
 *
 * @return  Length of raw data array
 */
static inline uint8_t mavlink_msg_cass_sensor_raw_get_app_datalength(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field values from cass_sensor_raw message
 *
 * @return  Raw data
 */
static inline uint16_t mavlink_msg_cass_sensor_raw_get_values(const mavlink_message_t* msg, float *values)
{
    return _MAV_RETURN_float_array(msg, values, 5,  4);
}

/**
 * @brief Decode a cass_sensor_raw message into a struct
 *
 * @param msg The message to decode
 * @param cass_sensor_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_cass_sensor_raw_decode(const mavlink_message_t* msg, mavlink_cass_sensor_raw_t* cass_sensor_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cass_sensor_raw->time_boot_ms = mavlink_msg_cass_sensor_raw_get_time_boot_ms(msg);
    mavlink_msg_cass_sensor_raw_get_values(msg, cass_sensor_raw->values);
    cass_sensor_raw->app_datatype = mavlink_msg_cass_sensor_raw_get_app_datatype(msg);
    cass_sensor_raw->app_datalength = mavlink_msg_cass_sensor_raw_get_app_datalength(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN? msg->len : MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN;
        memset(cass_sensor_raw, 0, MAVLINK_MSG_ID_CASS_SENSOR_RAW_LEN);
    memcpy(cass_sensor_raw, _MAV_PAYLOAD(msg), len);
#endif
}
