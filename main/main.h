//
//  main.h
//  esp32-ota-https
//
//  Updating the firmware over the air.
//
//  Created by Andreas Schweizer on 11.01.2017.
//  Copyright © 2017 Classy Code GmbH
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


#ifndef __MAIN_H__
#define __MAIN_H__ 1


// Adjust these values for your environment.
// -------------------------------------------------------------------------------------

// Used by the OTA module to check if the current version is different from the version
// on the server, i.e. if an upgrade or downgrade should be performed.
#define SOFTWARE_VERSION          1

// Provide the network name and password of your WIFI network.
#define WIFI_NETWORK_SSID         "VGV7519684538"
#define WIFI_NETWORK_PASSWORD     "bXXk8kcCHPvf"

// Provide server name, path to metadata file and polling interval for OTA updates.
#define OTA_SERVER_HOST_NAME      "smartplant.bassjansson.com"
#define OTA_SERVER_METADATA_PATH  "/esp32/ota.txt"
#define OTA_POLLING_INTERVAL_S    30
#define OTA_AUTO_REBOOT           1

// Provide the Root CA certificate for chain validation.
// (copied from gd_bundle-g2-g1.crt)
#define OTA_SERVER_ROOT_CA_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/MSQwIgYDVQQK\n"\
"ExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMTDkRTVCBSb290IENBIFgzMB4X\n"\
"DTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0NlowSjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxl\n"\
"dCdzIEVuY3J5cHQxIzAhBgNVBAMTGkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkq\n"\
"hkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4\n"\
"S0EFq6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8SMx+yk13\n"\
"EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0Z8h/pZq4UmEUEz9l6YKH\n"\
"y9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWAa6xK8xuQSXgvopZPKiAlKQTGdMDQMc2P\n"\
"MTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQAB\n"\
"o4IBfTCCAXkwEgYDVR0TAQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEE\n"\
"czBxMDIGCCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNvbTA7\n"\
"BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9kc3Ryb290Y2F4My5w\n"\
"N2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAwVAYDVR0gBE0wSzAIBgZngQwBAgEw\n"\
"PwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcCARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNy\n"\
"eXB0Lm9yZzA8BgNVHR8ENTAzMDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9P\n"\
"VENBWDNDUkwuY3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n"\
"AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJouM2VcGfl96S8\n"\
"TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/wApIvJSwtmVi4MFU5aMqrSDE\n"\
"6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwuX4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPM\n"\
"TZ+sOPAveyxindmjkW8lGy+QsRlGPfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M\n"\
"+X+Q7UNKEkROb3N6KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n"\
"-----END CERTIFICATE-----\n"

// Provide the Peer certificate for certificate pinning.
// (copied from classycode.io.crt)
#define OTA_PEER_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIGPjCCBSagAwIBAgISA+vEmhFTM0rMz8EbtzwHZA5bMA0GCSqGSIb3DQEBCwUA\n"\
"MEoxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MSMwIQYDVQQD\n"\
"ExpMZXQncyBFbmNyeXB0IEF1dGhvcml0eSBYMzAeFw0xODA2MDgxOTU2NDdaFw0x\n"\
"ODA5MDYxOTU2NDdaMCUxIzAhBgNVBAMTGnNtYXJ0cGxhbnQuYmFzc2phbnNzb24u\n"\
"Y29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvb7WYAnNM1XoyIYa\n"\
"ZkKZLFAsSytm4w8AFl5R2pg4U6tTrycALPqfVLMMUjOgydNHvO9IMhOkMN8p/6Zv\n"\
"TjiOs4755/2w608lK12yq+JhRm0XsGSofwlnZtekgzIn11HW4WSfo3FH2fQOcdoO\n"\
"QnZcxJoMbvF3/CBVz1b2qMk/K3uPcS1R4RwzhBBWhzrDNr5DAhwgXP8AsQ9lY2N6\n"\
"Luv2i6Wdhlji8l5Ij0jriSa0eNdyizifu84MD22mM2l54YBKHDmrRs4NyEKrwqHJ\n"\
"4oyzLI1s/MCFfKHHyJtbrbBAnVQOMWOU/T8uW8ccvGn0eKVvRrzzwVhnml5DCCFM\n"\
"a8hvVQIDAQABo4IDQTCCAz0wDgYDVR0PAQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsG\n"\
"AQUFBwMBBggrBgEFBQcDAjAMBgNVHRMBAf8EAjAAMB0GA1UdDgQWBBTdw30lSPIa\n"\
"jMBcVOVNfl7NtiFJKjAfBgNVHSMEGDAWgBSoSmpjBH3duubRObemRWXv86jsoTBv\n"\
"BggrBgEFBQcBAQRjMGEwLgYIKwYBBQUHMAGGImh0dHA6Ly9vY3NwLmludC14My5s\n"\
"ZXRzZW5jcnlwdC5vcmcwLwYIKwYBBQUHMAKGI2h0dHA6Ly9jZXJ0LmludC14My5s\n"\
"ZXRzZW5jcnlwdC5vcmcvMEUGA1UdEQQ+MDyCGnNtYXJ0cGxhbnQuYmFzc2phbnNz\n"\
"b24uY29tgh53d3cuc21hcnRwbGFudC5iYXNzamFuc3Nvbi5jb20wgf4GA1UdIASB\n"\
"9jCB8zAIBgZngQwBAgEwgeYGCysGAQQBgt8TAQEBMIHWMCYGCCsGAQUFBwIBFhpo\n"\
"dHRwOi8vY3BzLmxldHNlbmNyeXB0Lm9yZzCBqwYIKwYBBQUHAgIwgZ4MgZtUaGlz\n"\
"IENlcnRpZmljYXRlIG1heSBvbmx5IGJlIHJlbGllZCB1cG9uIGJ5IFJlbHlpbmcg\n"\
"UGFydGllcyBhbmQgb25seSBpbiBhY2NvcmRhbmNlIHdpdGggdGhlIENlcnRpZmlj\n"\
"YXRlIFBvbGljeSBmb3VuZCBhdCBodHRwczovL2xldHNlbmNyeXB0Lm9yZy9yZXBv\n"\
"c2l0b3J5LzCCAQMGCisGAQQB1nkCBAIEgfQEgfEA7wB2ANt0r+7LKeyx/so+cW0s\n"\
"5bmquzb3hHGDx12dTze2H79kAAABY+Ev+k0AAAQDAEcwRQIhAOJgpP5s7nPDPVt+\n"\
"zUDwJXkYuPnBKjR4/2rpJgdAxp3LAiANw14EJSRZYwgV4GZYoPoKgNfBfaHbj3kd\n"\
"CNgnGCC/+wB1ACk8UZZUyDlluqpQ/FgH1Ldvv1h6KXLcpMMM9OVFR/R4AAABY+Ev\n"\
"+l4AAAQDAEYwRAIgOnW+JPdYopW3PoYX/6c7hkNMZXWfKFn7TjdIDG0Ip9sCIAsN\n"\
"cK7WGJA4HsVYAgn9GHlCodkua8EUYtJXbAJ2LazeMA0GCSqGSIb3DQEBCwUAA4IB\n"\
"AQBmZhrckj4e3lZvz1AF9VxyHzTLTWB/+c8nzVzflyuC8bVMbouYHwvesHkyLwMZ\n"\
"r0KJU7tYXRjUA/+Zu324QHIFVj+pmGCCIrNqM0SAWFYPwIWkFrpFUKoJh3ISLt0Z\n"\
"a53sGQLRlp1pXp3IM7BJ3x0WZPeriIvBnAo4QuEfg5XrdV3ihi5j6sPkP244jh+i\n"\
"ZszE15bzMf9yNIMlIDex7ZBLocpx/xuyTvgqEfcm0U89jCc0Q9WKU+UdZa4n3dGg\n"\
"WHZ5SWB8I6PhJz6Aj+mr12H8Ibi7fmUL8PCtzg6YAOFj0ZQVTrjpjntxCQFJSS8H\n"\
"fCh9tz/xZHjCkIrHA/U+EJhU\n"\
"-----END CERTIFICATE-----\n"

// -------------------------------------------------------------------------------------


#endif // __MAIN_H__
