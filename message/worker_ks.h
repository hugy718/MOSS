#ifndef SECURE_SERVERLESS_MESSAGE_WORKERKS_H_
#define SECURE_SERVERLESS_MESSAGE_WORKERKS_H_

#include "request.h"

#include <string>

class GetKeyRequest : public Request {
 public:
  GetKeyRequest(const std::string& user_id, const std::string& model_id)
    : user_id_(user_id), model_id_(model_id){}
  ~GetKeyRequest() = default;

  std::string EncodeTo() const override;

  static GetKeyRequest DecodeFrom(const std::string& src); 

  inline const std::string& user_id() const { return user_id_; }
  inline const std::string& model_id() const { return model_id_; }
 private:
  const std::string user_id_;
  const std::string model_id_;
};

// /**
//  * @brief a set of functions used to encode and decode key service response
//  *  inside a enclave.
//  * 
//  */

// const char request_denial_msg[19] = "key request denied";
// const char user_not_found_msg[15] = "user not found";
// const char model_not_found_msg[16] = "model not found";

// int DecodeKSResponse(const char* msg, char* input_key_buf,
//   size_t input_key_buf_size, char* model_key_buf, size_t model_key_buf_size);

// /**
//  * @brief Encode the input key and model key to a string.
//  *  used by encalve inside key service. 
//  * 
//  * @param input_key : decryption key for client input 
//  * @param model_key : decryption key for the model (and its weight)
//  * @return KS response string representation
//  */
// std::string EncodeKSResponse(const std::string& input_key,
//   const std::string& model_key);

struct KeyServiceWorkerReply : public Reply {
  KeyServiceWorkerReply(const std::string& error_msg)
    : success_(false), msg_(error_msg) {}
  KeyServiceWorkerReply(const std::string& user_id,
    const std::string& input_key, const std::string& model_id,
    const std::string& model_key);
  ~KeyServiceWorkerReply() = default;
  std::string EncodeTo() const override;
  bool success_;
  std::string msg_;
};

// extern int DecodeKeyServiceWorkerReply(const std::string& reply,
//   char* input_key_buf, size_t input_key_buf_size, char* model_key_buf,
//   size_t model_key_buf_size);
extern int DecodeKeyServiceWorkerReply(const std::string& reply,
  std::string* user_id, std::string* input_key, std::string* model_id, std::string* model_key);

#endif  // SECURE_SERVERLESS_MESSAGE_WORKERKS_H_
