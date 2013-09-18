// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "player.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace camp {
namespace protocols {
namespace player {

void protobuf_ShutdownFile_player_2eproto() {
  delete HandShakingReq::default_instance_;
  delete HandShakingAck::default_instance_;
  delete LoginOrCreateAccountReq::default_instance_;
  delete LoginOrCreateAccountAck::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_player_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_player_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::camp::protocols::common::protobuf_AddDesc_common_2eproto();
  HandShakingReq::default_instance_ = new HandShakingReq();
  HandShakingAck::default_instance_ = new HandShakingAck();
  LoginOrCreateAccountReq::default_instance_ = new LoginOrCreateAccountReq();
  LoginOrCreateAccountAck::default_instance_ = new LoginOrCreateAccountAck();
  HandShakingReq::default_instance_->InitAsDefaultInstance();
  HandShakingAck::default_instance_->InitAsDefaultInstance();
  LoginOrCreateAccountReq::default_instance_->InitAsDefaultInstance();
  LoginOrCreateAccountAck::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_player_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_player_2eproto_once_);
void protobuf_AddDesc_player_2eproto() {
  ::google::protobuf::::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_player_2eproto_once_,
                 &protobuf_AddDesc_player_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_player_2eproto {
  StaticDescriptorInitializer_player_2eproto() {
    protobuf_AddDesc_player_2eproto();
  }
} static_descriptor_initializer_player_2eproto_;
#endif

// ===================================================================

#ifndef _MSC_VER
const int HandShakingReq::kClientVersionFieldNumber;
const int HandShakingReq::kSessionKeyFieldNumber;
#endif  // !_MSC_VER

HandShakingReq::HandShakingReq()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void HandShakingReq::InitAsDefaultInstance() {
}

HandShakingReq::HandShakingReq(const HandShakingReq& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void HandShakingReq::SharedCtor() {
  _cached_size_ = 0;
  client_version_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  session_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HandShakingReq::~HandShakingReq() {
  SharedDtor();
}

void HandShakingReq::SharedDtor() {
  if (client_version_ != &::google::protobuf::internal::kEmptyString) {
    delete client_version_;
  }
  if (session_key_ != &::google::protobuf::internal::kEmptyString) {
    delete session_key_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void HandShakingReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const HandShakingReq& HandShakingReq::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_player_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_player_2eproto();
#endif
  return *default_instance_;
}

HandShakingReq* HandShakingReq::default_instance_ = NULL;

HandShakingReq* HandShakingReq::New() const {
  return new HandShakingReq;
}

void HandShakingReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_client_version()) {
      if (client_version_ != &::google::protobuf::internal::kEmptyString) {
        client_version_->clear();
      }
    }
    if (has_session_key()) {
      if (session_key_ != &::google::protobuf::internal::kEmptyString) {
        session_key_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool HandShakingReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string client_version = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_version()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_session_key;
        break;
      }

      // optional string session_key = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_session_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_key()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void HandShakingReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string client_version = 1;
  if (has_client_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->client_version(), output);
  }

  // optional string session_key = 2;
  if (has_session_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->session_key(), output);
  }

}

int HandShakingReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string client_version = 1;
    if (has_client_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_version());
    }

    // optional string session_key = 2;
    if (has_session_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_key());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HandShakingReq::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const HandShakingReq*>(&from));
}

void HandShakingReq::MergeFrom(const HandShakingReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_client_version()) {
      set_client_version(from.client_version());
    }
    if (from.has_session_key()) {
      set_session_key(from.session_key());
    }
  }
}

void HandShakingReq::CopyFrom(const HandShakingReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HandShakingReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void HandShakingReq::Swap(HandShakingReq* other) {
  if (other != this) {
    std::swap(client_version_, other->client_version_);
    std::swap(session_key_, other->session_key_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string HandShakingReq::GetTypeName() const {
  return "camp.protocols.player.HandShakingReq";
}


// ===================================================================

bool HandShakingAck_AckError_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const HandShakingAck_AckError HandShakingAck::NO_ERROR;
const HandShakingAck_AckError HandShakingAck::CLIENT_UPDATE_REQUIRED;
const HandShakingAck_AckError HandShakingAck::INVALID_SESSION_KEY;
const HandShakingAck_AckError HandShakingAck::AckError_MIN;
const HandShakingAck_AckError HandShakingAck::AckError_MAX;
const int HandShakingAck::AckError_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int HandShakingAck::kErrorFieldNumber;
const int HandShakingAck::kSaltFieldNumber;
const int HandShakingAck::kRedirectToFieldNumber;
#endif  // !_MSC_VER

HandShakingAck::HandShakingAck()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void HandShakingAck::InitAsDefaultInstance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  redirect_to_ = const_cast< ::camp::protocols::common::Endpoint*>(
      ::camp::protocols::common::Endpoint::internal_default_instance());
#else
  redirect_to_ = const_cast< ::camp::protocols::common::Endpoint*>(&::camp::protocols::common::Endpoint::default_instance());
#endif
}

HandShakingAck::HandShakingAck(const HandShakingAck& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void HandShakingAck::SharedCtor() {
  _cached_size_ = 0;
  error_ = 0;
  salt_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  redirect_to_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HandShakingAck::~HandShakingAck() {
  SharedDtor();
}

void HandShakingAck::SharedDtor() {
  if (salt_ != &::google::protobuf::internal::kEmptyString) {
    delete salt_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
    delete redirect_to_;
  }
}

void HandShakingAck::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const HandShakingAck& HandShakingAck::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_player_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_player_2eproto();
#endif
  return *default_instance_;
}

HandShakingAck* HandShakingAck::default_instance_ = NULL;

HandShakingAck* HandShakingAck::New() const {
  return new HandShakingAck;
}

void HandShakingAck::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    error_ = 0;
    if (has_salt()) {
      if (salt_ != &::google::protobuf::internal::kEmptyString) {
        salt_->clear();
      }
    }
    if (has_redirect_to()) {
      if (redirect_to_ != NULL) redirect_to_->::camp::protocols::common::Endpoint::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool HandShakingAck::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .camp.protocols.player.HandShakingAck.AckError error = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::camp::protocols::player::HandShakingAck_AckError_IsValid(value)) {
            set_error(static_cast< ::camp::protocols::player::HandShakingAck_AckError >(value));
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_salt;
        break;
      }

      // optional string salt = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_salt:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_salt()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_redirect_to;
        break;
      }

      // optional .camp.protocols.common.Endpoint redirect_to = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_redirect_to:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_redirect_to()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void HandShakingAck::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .camp.protocols.player.HandShakingAck.AckError error = 1;
  if (has_error()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->error(), output);
  }

  // optional string salt = 2;
  if (has_salt()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->salt(), output);
  }

  // optional .camp.protocols.common.Endpoint redirect_to = 3;
  if (has_redirect_to()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, this->redirect_to(), output);
  }

}

int HandShakingAck::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .camp.protocols.player.HandShakingAck.AckError error = 1;
    if (has_error()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->error());
    }

    // optional string salt = 2;
    if (has_salt()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->salt());
    }

    // optional .camp.protocols.common.Endpoint redirect_to = 3;
    if (has_redirect_to()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->redirect_to());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HandShakingAck::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const HandShakingAck*>(&from));
}

void HandShakingAck::MergeFrom(const HandShakingAck& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error()) {
      set_error(from.error());
    }
    if (from.has_salt()) {
      set_salt(from.salt());
    }
    if (from.has_redirect_to()) {
      mutable_redirect_to()->::camp::protocols::common::Endpoint::MergeFrom(from.redirect_to());
    }
  }
}

void HandShakingAck::CopyFrom(const HandShakingAck& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HandShakingAck::IsInitialized() const {

  if (has_redirect_to()) {
    if (!this->redirect_to().IsInitialized()) return false;
  }
  return true;
}

void HandShakingAck::Swap(HandShakingAck* other) {
  if (other != this) {
    std::swap(error_, other->error_);
    std::swap(salt_, other->salt_);
    std::swap(redirect_to_, other->redirect_to_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string HandShakingAck::GetTypeName() const {
  return "camp.protocols.player.HandShakingAck";
}


// ===================================================================

#ifndef _MSC_VER
const int LoginOrCreateAccountReq::kAuthTokenFieldNumber;
#endif  // !_MSC_VER

LoginOrCreateAccountReq::LoginOrCreateAccountReq()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void LoginOrCreateAccountReq::InitAsDefaultInstance() {
}

LoginOrCreateAccountReq::LoginOrCreateAccountReq(const LoginOrCreateAccountReq& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void LoginOrCreateAccountReq::SharedCtor() {
  _cached_size_ = 0;
  auth_token_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LoginOrCreateAccountReq::~LoginOrCreateAccountReq() {
  SharedDtor();
}

void LoginOrCreateAccountReq::SharedDtor() {
  if (auth_token_ != &::google::protobuf::internal::kEmptyString) {
    delete auth_token_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void LoginOrCreateAccountReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const LoginOrCreateAccountReq& LoginOrCreateAccountReq::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_player_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_player_2eproto();
#endif
  return *default_instance_;
}

LoginOrCreateAccountReq* LoginOrCreateAccountReq::default_instance_ = NULL;

LoginOrCreateAccountReq* LoginOrCreateAccountReq::New() const {
  return new LoginOrCreateAccountReq;
}

void LoginOrCreateAccountReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_auth_token()) {
      if (auth_token_ != &::google::protobuf::internal::kEmptyString) {
        auth_token_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool LoginOrCreateAccountReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string auth_token = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_auth_token()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void LoginOrCreateAccountReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string auth_token = 1;
  if (has_auth_token()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->auth_token(), output);
  }

}

int LoginOrCreateAccountReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string auth_token = 1;
    if (has_auth_token()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->auth_token());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LoginOrCreateAccountReq::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const LoginOrCreateAccountReq*>(&from));
}

void LoginOrCreateAccountReq::MergeFrom(const LoginOrCreateAccountReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_auth_token()) {
      set_auth_token(from.auth_token());
    }
  }
}

void LoginOrCreateAccountReq::CopyFrom(const LoginOrCreateAccountReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginOrCreateAccountReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void LoginOrCreateAccountReq::Swap(LoginOrCreateAccountReq* other) {
  if (other != this) {
    std::swap(auth_token_, other->auth_token_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string LoginOrCreateAccountReq::GetTypeName() const {
  return "camp.protocols.player.LoginOrCreateAccountReq";
}


// ===================================================================

bool LoginOrCreateAccountAck_AckError_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const LoginOrCreateAccountAck_AckError LoginOrCreateAccountAck::NO_ERROR;
const LoginOrCreateAccountAck_AckError LoginOrCreateAccountAck::INVALID_AUTH_TOKEN;
const LoginOrCreateAccountAck_AckError LoginOrCreateAccountAck::AckError_MIN;
const LoginOrCreateAccountAck_AckError LoginOrCreateAccountAck::AckError_MAX;
const int LoginOrCreateAccountAck::AckError_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int LoginOrCreateAccountAck::kErrorFieldNumber;
const int LoginOrCreateAccountAck::kSessionKeyFieldNumber;
#endif  // !_MSC_VER

LoginOrCreateAccountAck::LoginOrCreateAccountAck()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void LoginOrCreateAccountAck::InitAsDefaultInstance() {
}

LoginOrCreateAccountAck::LoginOrCreateAccountAck(const LoginOrCreateAccountAck& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void LoginOrCreateAccountAck::SharedCtor() {
  _cached_size_ = 0;
  error_ = 0;
  session_key_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LoginOrCreateAccountAck::~LoginOrCreateAccountAck() {
  SharedDtor();
}

void LoginOrCreateAccountAck::SharedDtor() {
  if (session_key_ != &::google::protobuf::internal::kEmptyString) {
    delete session_key_;
  }
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
  }
}

void LoginOrCreateAccountAck::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const LoginOrCreateAccountAck& LoginOrCreateAccountAck::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_player_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_player_2eproto();
#endif
  return *default_instance_;
}

LoginOrCreateAccountAck* LoginOrCreateAccountAck::default_instance_ = NULL;

LoginOrCreateAccountAck* LoginOrCreateAccountAck::New() const {
  return new LoginOrCreateAccountAck;
}

void LoginOrCreateAccountAck::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    error_ = 0;
    if (has_session_key()) {
      if (session_key_ != &::google::protobuf::internal::kEmptyString) {
        session_key_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool LoginOrCreateAccountAck::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .camp.protocols.player.LoginOrCreateAccountAck.AckError error = 1 [default = NO_ERROR];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::camp::protocols::player::LoginOrCreateAccountAck_AckError_IsValid(value)) {
            set_error(static_cast< ::camp::protocols::player::LoginOrCreateAccountAck_AckError >(value));
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_session_key;
        break;
      }

      // optional string session_key = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_session_key:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_session_key()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void LoginOrCreateAccountAck::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .camp.protocols.player.LoginOrCreateAccountAck.AckError error = 1 [default = NO_ERROR];
  if (has_error()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->error(), output);
  }

  // optional string session_key = 2;
  if (has_session_key()) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->session_key(), output);
  }

}

int LoginOrCreateAccountAck::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .camp.protocols.player.LoginOrCreateAccountAck.AckError error = 1 [default = NO_ERROR];
    if (has_error()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->error());
    }

    // optional string session_key = 2;
    if (has_session_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->session_key());
    }

  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LoginOrCreateAccountAck::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const LoginOrCreateAccountAck*>(&from));
}

void LoginOrCreateAccountAck::MergeFrom(const LoginOrCreateAccountAck& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_error()) {
      set_error(from.error());
    }
    if (from.has_session_key()) {
      set_session_key(from.session_key());
    }
  }
}

void LoginOrCreateAccountAck::CopyFrom(const LoginOrCreateAccountAck& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginOrCreateAccountAck::IsInitialized() const {

  return true;
}

void LoginOrCreateAccountAck::Swap(LoginOrCreateAccountAck* other) {
  if (other != this) {
    std::swap(error_, other->error_);
    std::swap(session_key_, other->session_key_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string LoginOrCreateAccountAck::GetTypeName() const {
  return "camp.protocols.player.LoginOrCreateAccountAck";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace player
}  // namespace protocols
}  // namespace camp

// @@protoc_insertion_point(global_scope)
