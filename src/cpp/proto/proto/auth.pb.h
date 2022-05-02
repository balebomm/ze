// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: auth.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_auth_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_auth_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_auth_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_auth_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_auth_2eproto;
namespace proto {
class Auth_LoginRequest;
struct Auth_LoginRequestDefaultTypeInternal;
extern Auth_LoginRequestDefaultTypeInternal _Auth_LoginRequest_default_instance_;
class Auth_LoginResponse;
struct Auth_LoginResponseDefaultTypeInternal;
extern Auth_LoginResponseDefaultTypeInternal _Auth_LoginResponse_default_instance_;
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::Auth_LoginRequest* Arena::CreateMaybeMessage<::proto::Auth_LoginRequest>(Arena*);
template<> ::proto::Auth_LoginResponse* Arena::CreateMaybeMessage<::proto::Auth_LoginResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {

// ===================================================================

class Auth_LoginRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.Auth_LoginRequest) */ {
 public:
  inline Auth_LoginRequest() : Auth_LoginRequest(nullptr) {}
  ~Auth_LoginRequest() override;
  explicit constexpr Auth_LoginRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Auth_LoginRequest(const Auth_LoginRequest& from);
  Auth_LoginRequest(Auth_LoginRequest&& from) noexcept
    : Auth_LoginRequest() {
    *this = ::std::move(from);
  }

  inline Auth_LoginRequest& operator=(const Auth_LoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline Auth_LoginRequest& operator=(Auth_LoginRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Auth_LoginRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const Auth_LoginRequest* internal_default_instance() {
    return reinterpret_cast<const Auth_LoginRequest*>(
               &_Auth_LoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Auth_LoginRequest& a, Auth_LoginRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(Auth_LoginRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Auth_LoginRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Auth_LoginRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Auth_LoginRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Auth_LoginRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Auth_LoginRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Auth_LoginRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.Auth_LoginRequest";
  }
  protected:
  explicit Auth_LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUsernameFieldNumber = 1,
    kPasswordFieldNumber = 2,
  };
  // string username = 1;
  void clear_username();
  const std::string& username() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_username(ArgT0&& arg0, ArgT... args);
  std::string* mutable_username();
  PROTOBUF_NODISCARD std::string* release_username();
  void set_allocated_username(std::string* username);
  private:
  const std::string& _internal_username() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_username(const std::string& value);
  std::string* _internal_mutable_username();
  public:

  // string password = 2;
  void clear_password();
  const std::string& password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_password();
  PROTOBUF_NODISCARD std::string* release_password();
  void set_allocated_password(std::string* password);
  private:
  const std::string& _internal_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // @@protoc_insertion_point(class_scope:proto.Auth_LoginRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr username_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_auth_2eproto;
};
// -------------------------------------------------------------------

class Auth_LoginResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.Auth_LoginResponse) */ {
 public:
  inline Auth_LoginResponse() : Auth_LoginResponse(nullptr) {}
  ~Auth_LoginResponse() override;
  explicit constexpr Auth_LoginResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Auth_LoginResponse(const Auth_LoginResponse& from);
  Auth_LoginResponse(Auth_LoginResponse&& from) noexcept
    : Auth_LoginResponse() {
    *this = ::std::move(from);
  }

  inline Auth_LoginResponse& operator=(const Auth_LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline Auth_LoginResponse& operator=(Auth_LoginResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Auth_LoginResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const Auth_LoginResponse* internal_default_instance() {
    return reinterpret_cast<const Auth_LoginResponse*>(
               &_Auth_LoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Auth_LoginResponse& a, Auth_LoginResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(Auth_LoginResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Auth_LoginResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Auth_LoginResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Auth_LoginResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Auth_LoginResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Auth_LoginResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Auth_LoginResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.Auth_LoginResponse";
  }
  protected:
  explicit Auth_LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSessionFieldNumber = 1,
  };
  // string session = 1;
  void clear_session();
  const std::string& session() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_session(ArgT0&& arg0, ArgT... args);
  std::string* mutable_session();
  PROTOBUF_NODISCARD std::string* release_session();
  void set_allocated_session(std::string* session);
  private:
  const std::string& _internal_session() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_session(const std::string& value);
  std::string* _internal_mutable_session();
  public:

  // @@protoc_insertion_point(class_scope:proto.Auth_LoginResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr session_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_auth_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Auth_LoginRequest

// string username = 1;
inline void Auth_LoginRequest::clear_username() {
  username_.ClearToEmpty();
}
inline const std::string& Auth_LoginRequest::username() const {
  // @@protoc_insertion_point(field_get:proto.Auth_LoginRequest.username)
  return _internal_username();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Auth_LoginRequest::set_username(ArgT0&& arg0, ArgT... args) {
 
 username_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.Auth_LoginRequest.username)
}
inline std::string* Auth_LoginRequest::mutable_username() {
  std::string* _s = _internal_mutable_username();
  // @@protoc_insertion_point(field_mutable:proto.Auth_LoginRequest.username)
  return _s;
}
inline const std::string& Auth_LoginRequest::_internal_username() const {
  return username_.Get();
}
inline void Auth_LoginRequest::_internal_set_username(const std::string& value) {
  
  username_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Auth_LoginRequest::_internal_mutable_username() {
  
  return username_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Auth_LoginRequest::release_username() {
  // @@protoc_insertion_point(field_release:proto.Auth_LoginRequest.username)
  return username_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Auth_LoginRequest::set_allocated_username(std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  username_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), username,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (username_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    username_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.Auth_LoginRequest.username)
}

// string password = 2;
inline void Auth_LoginRequest::clear_password() {
  password_.ClearToEmpty();
}
inline const std::string& Auth_LoginRequest::password() const {
  // @@protoc_insertion_point(field_get:proto.Auth_LoginRequest.password)
  return _internal_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Auth_LoginRequest::set_password(ArgT0&& arg0, ArgT... args) {
 
 password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.Auth_LoginRequest.password)
}
inline std::string* Auth_LoginRequest::mutable_password() {
  std::string* _s = _internal_mutable_password();
  // @@protoc_insertion_point(field_mutable:proto.Auth_LoginRequest.password)
  return _s;
}
inline const std::string& Auth_LoginRequest::_internal_password() const {
  return password_.Get();
}
inline void Auth_LoginRequest::_internal_set_password(const std::string& value) {
  
  password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Auth_LoginRequest::_internal_mutable_password() {
  
  return password_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Auth_LoginRequest::release_password() {
  // @@protoc_insertion_point(field_release:proto.Auth_LoginRequest.password)
  return password_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Auth_LoginRequest::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), password,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (password_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.Auth_LoginRequest.password)
}

// -------------------------------------------------------------------

// Auth_LoginResponse

// string session = 1;
inline void Auth_LoginResponse::clear_session() {
  session_.ClearToEmpty();
}
inline const std::string& Auth_LoginResponse::session() const {
  // @@protoc_insertion_point(field_get:proto.Auth_LoginResponse.session)
  return _internal_session();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Auth_LoginResponse::set_session(ArgT0&& arg0, ArgT... args) {
 
 session_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.Auth_LoginResponse.session)
}
inline std::string* Auth_LoginResponse::mutable_session() {
  std::string* _s = _internal_mutable_session();
  // @@protoc_insertion_point(field_mutable:proto.Auth_LoginResponse.session)
  return _s;
}
inline const std::string& Auth_LoginResponse::_internal_session() const {
  return session_.Get();
}
inline void Auth_LoginResponse::_internal_set_session(const std::string& value) {
  
  session_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Auth_LoginResponse::_internal_mutable_session() {
  
  return session_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Auth_LoginResponse::release_session() {
  // @@protoc_insertion_point(field_release:proto.Auth_LoginResponse.session)
  return session_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Auth_LoginResponse::set_allocated_session(std::string* session) {
  if (session != nullptr) {
    
  } else {
    
  }
  session_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), session,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (session_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    session_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.Auth_LoginResponse.session)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_auth_2eproto