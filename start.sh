#!/bin/bash
DISPLAY=$(w -h | grep $USER | awk '{print $3}')
/home/esko/OmatProjektit/BatteryMon/BatteryMon
