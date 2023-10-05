#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include <vector>

#include "restricted_ref_counter.hpp"

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at
   least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw
   pointer refers to. The data returned should be such that modifying it
   modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw
   pointer
        - function GetRefCount that takes no parameters and returns an int with
   the reference count

    At any time the objects should keep track of how many references there are
   to a pointer and not allow more than 3 references. If the reference count
   drops to 0, the referenced pointer's memory should be released. If the
   reference count is already 3 when copying, the copier should set it's pointer
   to nullptr and reference count to 1. NOTE: GetPointer, GetData and
   GetRefCount are needed for the tests to run
*/
template <typename T>
class RestrictedPtr {
 public:
  RestrictedPtr() : ptr_(nullptr), use_count_(nullptr) {}
  RestrictedPtr(T* ptr) : ptr_(ptr) { use_count_ = new int(1); }
  RestrictedPtr(RestrictedPtr& p) {
    if (*p.use_count_ == 3) {
      use_count_ = new int(1);
      ptr_ = nullptr;
    } else {
      ptr_ = p.ptr_;
      use_count_ = p.use_count_;
      ++*use_count_;
    }
  }
  ~RestrictedPtr() {
    if (use_count_ != nullptr) {
      --*use_count_;
      if (*use_count_ == 0) {
        delete use_count_;
        if (ptr_ != nullptr) {
          delete ptr_;
        }
      }
    }
  }
  RestrictedPtr& operator=(const RestrictedPtr& p) {
    if (use_count_ == nullptr) {
      if (*p.use_count_ == 3) {
        use_count_ = new int(1);
        ptr_ = nullptr;
      } else {
        ptr_ = p.ptr_;
        use_count_ = p.use_count_;
        ++*use_count_;
      }
    } else {
      --*use_count_;
      if (*use_count_ == 0) {
        delete use_count_;
        if (ptr_ != nullptr) {
          delete ptr_;
        }
      }

      if (*p.use_count_ == 3) {
        use_count_ = new int(1);
        ptr_ = nullptr;
      } else {
        ptr_ = p.ptr_;
        use_count_ = p.use_count_;
        ++*use_count_;
      }
    }
    return this;
  }
  T& GetData() { return *ptr_; }
  T* GetPointer() { return ptr_; }
  int GetRefCount() { return *use_count_; }

 private:
  T* ptr_ = nullptr;
  int* use_count_ = nullptr;
};

#endif