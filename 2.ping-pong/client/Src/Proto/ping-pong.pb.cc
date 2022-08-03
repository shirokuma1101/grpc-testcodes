// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ping-pong.proto

#include "ping-pong.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr Ping::Ping(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : time_(uint64_t{0u}){}
struct PingDefaultTypeInternal {
  constexpr PingDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PingDefaultTypeInternal() {}
  union {
    Ping _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PingDefaultTypeInternal _Ping_default_instance_;
constexpr Pong::Pong(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : time_(uint64_t{0u}){}
struct PongDefaultTypeInternal {
  constexpr PongDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PongDefaultTypeInternal() {}
  union {
    Pong _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PongDefaultTypeInternal _Pong_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ping_2dpong_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ping_2dpong_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ping_2dpong_2eproto = nullptr;

const uint32_t TableStruct_ping_2dpong_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Ping, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Ping, time_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Pong, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Pong, time_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Ping)},
  { 7, -1, -1, sizeof(::Pong)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Ping_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Pong_default_instance_),
};

const char descriptor_table_protodef_ping_2dpong_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017ping-pong.proto\"\024\n\004Ping\022\014\n\004time\030\001 \001(\006\""
  "\024\n\004Pong\022\014\n\004time\030\001 \001(\0062&\n\010PingPong\022\032\n\010Sen"
  "dPing\022\005.Ping\032\005.Pong\"\000b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ping_2dpong_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ping_2dpong_2eproto = {
  false, false, 109, descriptor_table_protodef_ping_2dpong_2eproto, "ping-pong.proto", 
  &descriptor_table_ping_2dpong_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_ping_2dpong_2eproto::offsets,
  file_level_metadata_ping_2dpong_2eproto, file_level_enum_descriptors_ping_2dpong_2eproto, file_level_service_descriptors_ping_2dpong_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_ping_2dpong_2eproto_getter() {
  return &descriptor_table_ping_2dpong_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_ping_2dpong_2eproto(&descriptor_table_ping_2dpong_2eproto);

// ===================================================================

class Ping::_Internal {
 public:
};

Ping::Ping(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Ping)
}
Ping::Ping(const Ping& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  time_ = from.time_;
  // @@protoc_insertion_point(copy_constructor:Ping)
}

inline void Ping::SharedCtor() {
time_ = uint64_t{0u};
}

Ping::~Ping() {
  // @@protoc_insertion_point(destructor:Ping)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Ping::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Ping::ArenaDtor(void* object) {
  Ping* _this = reinterpret_cast< Ping* >(object);
  (void)_this;
}
void Ping::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Ping::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Ping::Clear() {
// @@protoc_insertion_point(message_clear_start:Ping)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  time_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Ping::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // fixed64 time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint64_t>(ptr);
          ptr += sizeof(uint64_t);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Ping::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Ping)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // fixed64 time = 1;
  if (this->_internal_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(1, this->_internal_time(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Ping)
  return target;
}

size_t Ping::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Ping)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // fixed64 time = 1;
  if (this->_internal_time() != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Ping::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Ping::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Ping::GetClassData() const { return &_class_data_; }

void Ping::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Ping *>(to)->MergeFrom(
      static_cast<const Ping &>(from));
}


void Ping::MergeFrom(const Ping& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Ping)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_time() != 0) {
    _internal_set_time(from._internal_time());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Ping::CopyFrom(const Ping& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Ping)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ping::IsInitialized() const {
  return true;
}

void Ping::InternalSwap(Ping* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(time_, other->time_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Ping::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ping_2dpong_2eproto_getter, &descriptor_table_ping_2dpong_2eproto_once,
      file_level_metadata_ping_2dpong_2eproto[0]);
}

// ===================================================================

class Pong::_Internal {
 public:
};

Pong::Pong(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Pong)
}
Pong::Pong(const Pong& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  time_ = from.time_;
  // @@protoc_insertion_point(copy_constructor:Pong)
}

inline void Pong::SharedCtor() {
time_ = uint64_t{0u};
}

Pong::~Pong() {
  // @@protoc_insertion_point(destructor:Pong)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Pong::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Pong::ArenaDtor(void* object) {
  Pong* _this = reinterpret_cast< Pong* >(object);
  (void)_this;
}
void Pong::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Pong::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Pong::Clear() {
// @@protoc_insertion_point(message_clear_start:Pong)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  time_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Pong::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // fixed64 time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 9)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint64_t>(ptr);
          ptr += sizeof(uint64_t);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Pong::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Pong)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // fixed64 time = 1;
  if (this->_internal_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(1, this->_internal_time(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Pong)
  return target;
}

size_t Pong::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Pong)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // fixed64 time = 1;
  if (this->_internal_time() != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Pong::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Pong::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Pong::GetClassData() const { return &_class_data_; }

void Pong::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Pong *>(to)->MergeFrom(
      static_cast<const Pong &>(from));
}


void Pong::MergeFrom(const Pong& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Pong)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_time() != 0) {
    _internal_set_time(from._internal_time());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Pong::CopyFrom(const Pong& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Pong)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Pong::IsInitialized() const {
  return true;
}

void Pong::InternalSwap(Pong* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(time_, other->time_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Pong::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_ping_2dpong_2eproto_getter, &descriptor_table_ping_2dpong_2eproto_once,
      file_level_metadata_ping_2dpong_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Ping* Arena::CreateMaybeMessage< ::Ping >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Ping >(arena);
}
template<> PROTOBUF_NOINLINE ::Pong* Arena::CreateMaybeMessage< ::Pong >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Pong >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>