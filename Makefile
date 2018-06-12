#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := esp32-ota-https
CFLAGS += -save-temps

include $(IDF_PATH)/make/project.mk

SERVER_HOST = bj.com
SERVER_PORT = 4000
SERVER_PATH = ~/subdomains/smartplant/esp32/

upload:
	scp -P $(SERVER_PORT) build/esp32-ota-https.bin $(SERVER_HOST):$(SERVER_PATH)
	scp -P $(SERVER_PORT) meta/ota.txt $(SERVER_HOST):$(SERVER_PATH)
