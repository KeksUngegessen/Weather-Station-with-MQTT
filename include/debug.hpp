#pragma once

#ifdef DEBUG

// Begin Serial transmission and wait until its ports are open.
#define SETUP_SERIAL(baud) \
  Serial.begin(baud);      \
  while (!Serial)          \
    ;                      \
  Serial.println();        \
  Serial.println()

// Print to Serial.
#define LOG(printable) Serial.print(printable)
#define LOG_LN(printable) Serial.println(printable)

// Print a string from a MQTT Error Code describing
// the failure reason to Serial.
#define LOG_MQTT_ERROR_CODE(errorCode)                      \
  LOG("Connection failed! Error code: ");                   \
  LOG(errorCode);                                           \
  LOG(" -> ");                                              \
  switch (errorCode) {                                      \
    case MQTT_CONNECTION_REFUSED:                           \
      Serial.println("MQTT_CONNECTION_REFUSED");            \
      break;                                                \
    case MQTT_UNACCEPTABLE_PROTOCOL_VERSION:                \
      Serial.println("MQTT_UNACCEPTABLE_PROTOCOL_VERSION"); \
      break;                                                \
    case MQTT_SUCCESS:                                      \
      Serial.println("MQTT_SUCCESS");                       \
      break;                                                \
    case MQTT_IDENTIFIER_REJECTED:                          \
      Serial.println("MQTT_IDENTIFIER_REJECTED");           \
      break;                                                \
    case MQTT_SERVER_UNAVAILABLE:                           \
      Serial.println("MQTT_SERVER_UNAVAILABLE");            \
      break;                                                \
    case MQTT_BAD_USER_NAME_OR_PASSWORD:                    \
      Serial.println("MQTT_BAD_USER_NAME_OR_PASSWORD");     \
      break;                                                \
    case MQTT_NOT_AUTHORIZED:                               \
      Serial.println("MQTT_NOT_AUTHORIZED");                \
      break;                                                \
    case MQTT_CONNECTION_TIMEOUT:                           \
      Serial.println("MQTT_CONNECTION_TIMEOUT");            \
      break;                                                \
    default:                                                \
      break;                                                \
  }                                                         \
  Serial.println("Will try again in 30 seconds.")
// Print a string from a WiFi Status Code describing
// the current status of the connection to Serial.
#define LOG_WIFI_STATUS_CODE(statusCode)   \
  switch (statusCode) {                    \
    case WL_CONNECTED:                     \
      Serial.println("WL_CONNECTED");      \
      break;                               \
    case WL_NO_SSID_AVAIL:                 \
      Serial.println("WL_NO_SSID_AVAIL");  \
      break;                               \
    case WL_CONNECT_FAILED:                \
      Serial.println("WL_CONNECT_FAILED"); \
      break;                               \
    case WL_WRONG_PASSWORD:                \
      Serial.println("WL_WRONG_PASSWORD"); \
      break;                               \
    case WL_IDLE_STATUS:                   \
      Serial.println("WL_IDLE_STATUS");    \
      break;                               \
    default:                               \
      Serial.println("WL_DISCONNECTED");   \
      break;                               \
  }

// Print details about a sensor.
#define LOG_SENSOR_DETES(sensor, unit)                       \
  LOG_LN("Sensor Type: " + String(sensor.name));             \
  LOG_LN("Driver Ver:  " + String(sensor.version));          \
  LOG_LN("Unique ID:   " + String(sensor.sensor_id));        \
  LOG_LN("Max Value:   " + String(sensor.max_value) + unit); \
  LOG_LN("Min Value:   " + String(sensor.min_value) + unit); \
  LOG_LN("Accuracy:    " + String(sensor.resolution) + unit);

#else

#define SETUP_SERIAL(baud) (void)0

#define LOG(printable) (void)0
#define LOG_LN(printable) (void)0

#define LOG_WIFI_STATUS_CODE(errorCode) (void)0
#define LOG_MQTT_ERROR_CODE(statusCode) (void)0

#define LOG_SENSOR_DETES(sensor, unit) (void)0

#endif  // DEBUG
