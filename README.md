# MOSS

A secure cloud-native serverless model serving system

## Prepare SGX machines

The project has been tested with `Ubuntu 20.04` with kernel `5.13.0.41-generic`. Intel SGX: SDK/PSW 2.14 - other libraries 1.11 (matching library version is important).

The machines should be installed with `Intel SGX AESM` service and the `Intel DCAP-ECDSA` attestation infrastructure setup. refer to <https://www.intel.com/content/www/us/en/developer/articles/technical/quote-verification-attestation-with-intel-sgx-dcap.html> to setup the SGX environment.

## Build

1. Clone this repository locally and run `make preparation` to initialize all external dependencies.
2. refer to the README under `docker` folder to build respective dockers (client, KeyService, MossRT).
