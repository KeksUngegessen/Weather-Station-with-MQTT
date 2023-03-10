#pragma once

#include <ArduinoJson.h>

#include "debug.hpp"

// WIFI

// Connect to a Wifi AP.
// Blocks program as long as a connection cannot be established.
void connectToWiFi();

// MQTT

/**
 * Connect to a MQTT Broker.
 * Blocks the program as long as a connection is being established.
 */
void connectToMQTT(unsigned long keepAliveInterval);

/**
 * Send a message to a specific MQTT topic.
 */
void sendMQTTMessage(const String& topic, const String& payload, short qos = 0);

/**
 * Send a message to a specific MQTT topic.
 */
void sendMQTTMessage(const String& topic, StaticJsonDocument<300>& jsonDoc, short qos = 0);
