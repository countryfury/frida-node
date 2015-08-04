#ifndef FRIDANODE_DEVICE_MANAGER_H
#define FRIDANODE_DEVICE_MANAGER_H

#include "glib_object.h"

#include <frida-core.h>

namespace frida {

class DeviceManager : public GLibObject {
 public:
  static void Init(v8::Handle<v8::Object> exports, Runtime* runtime);
  static void Dispose(Runtime* runtime);

 private:
  DeviceManager(FridaDeviceManager* handle, Runtime* runtime);
  ~DeviceManager();

  static NAN_METHOD(New);

  static NAN_METHOD(Close);
  static NAN_METHOD(EnumerateDevices);

  static void OnListen(const gchar* signal, gpointer user_data);
  static void OnUnlisten(const gchar* signal, gpointer user_data);

  v8::Persistent<v8::Object> events_;
};

}

#endif
