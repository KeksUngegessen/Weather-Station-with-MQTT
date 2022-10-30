#include <Arduino.h>

#include "sensors.hpp"

WindSensor::WindSensor(uint8_t speedPin, uint8_t northPin, uint8_t eastPin, uint8_t southPin, uint8_t westPin) {
  speedPin_ = speedPin;
  northPin_ = northPin;
  eastPin_ = eastPin;
  southPin_ = southPin;
  westPin_ = westPin;
  pinMode(speedPin_, INPUT);
  pinMode(northPin_, INPUT);
  pinMode(eastPin_, INPUT);
  pinMode(southPin_, INPUT);
  pinMode(westPin_, INPUT);
}

float WindSensor::readSpeed() {  // TODO
  float speed = digitalRead(speedPin_);
  LOG_LN("Wind speed: " + String(speed) + " km/h");
  return speed;
}

WindSensor::WindDirection WindSensor::readDirection() {
  if (digitalRead(northPin_)) {
    if (digitalRead(eastPin_)) {
      windDir_ = WindDirection::NORTH_EAST;
    } else if (digitalRead(westPin_)) {
      windDir_ = WindDirection::NORTH_WEST;
    } else {
      windDir_ = WindDirection::NORTH;
    }

  } else if (digitalRead(southPin_)) {
    if (digitalRead(eastPin_)) {
      windDir_ = WindDirection::SOUTH_EAST;
    } else if (digitalRead(westPin_)) {
      windDir_ = WindDirection::SOUTH_WEST;
    } else {
      windDir_ = WindDirection::SOUTH;
    }

  } else if (digitalRead(eastPin_)) {
    windDir_ = WindDirection::EAST;

  } else if (digitalRead(westPin_)) {
    windDir_ = WindDirection::WEST;
  }

  LOG_LN("Wind Direction: " + WindSensor::getString(windDir_));
  return windDir_;
}

String WindSensor::getString(WindSensor::WindDirection direction) {
  switch (direction) {
    case 0:
      return "N";
      break;
    case 1:
      return "NE";
      break;
    case 2:
      return "E";
      break;
    case 3:
      return "SE";
      break;
    case 4:
      return "S";
      break;
    case 5:
      return "SW";
      break;
    case 6:
      return "W";
      break;
    case 7:
      return "NW";
      break;

    default:
      LOG_LN("Unknown wind direction.");
      return "";
  }
}