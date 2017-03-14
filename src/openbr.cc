// addon.cc
#include <node.h>
#include <nan.h>
#include <openbr/openbr_plugin.h>
#include <QString>

namespace addon {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::String;
using v8::Object;
using v8::String;
using v8::Value;

// static void printTemplate(const br::Template &t) {
//   printf("%s age: %d\n", qPrintable(t.file.fileName()), int(t.file.get<float>("Age")));
// }

// This is the implementation of the "ageEstimation" method
// Input arguments are passed using the
// const FunctionCallbackInfo<Value>& args struct
void AgeEstimation(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() < 1) {
    // Throw an Error that is passed back to JavaScript
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  // Check the argument types
  if (!args[0]->IsString()) {
    Nan::ThrowTypeError("Wront type of arguments");
    return;
  }

  String::Utf8Value str(args[0]->ToString());
  printf("Loading file %s\n", (const char*)(*str));

  // Initialize openbr context
  char *argv[] = {NULL};
  int argc = sizeof(argv) / sizeof(char*) - 1;
  br::Context::initialize(argc, argv);

  // Retrieve class for enrolling templates using the AgeEstimation algorithm
  QSharedPointer<br::Transform> transform = br::Transform::fromAlgorithm("AgeEstimation");

  // Initialize templates
  br::Template queryA((const char*)(*str));
  // br::Template queryB("/srv/node/data/b.jpg");

  // Enroll templates
  br::Globals->enrollAll = false; // Enroll exactly one face per image
  queryA >> *transform;
  // queryB >> *transform;

  br::Context::finalize();

  // Perform the operation
  // double value = args[0]->NumberValue() + args[1]->NumberValue();
  Local<Number> num = Number::New(isolate, queryA.file.get<float>("Age"));

  // Set the return value (using the passed in
  // FunctionCallbackInfo<Value>&)
  args.GetReturnValue().Set(num);
}

// This is the implementation of the "genderEstimation" method
// Input arguments are passed using the
// const FunctionCallbackInfo<Value>& args struct
void GenderEstimation(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() < 1) {
    // Throw an Error that is passed back to JavaScript
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  // Check the argument types
  if (!args[0]->IsString()) {
    Nan::ThrowTypeError("Wront type of arguments");
    return;
  }

  String::Utf8Value str(args[0]->ToString());
  printf("Loading file %s\n", (const char*)(*str));

  // Initialize openbr context
  char *argv[] = {NULL};
  int argc = sizeof(argv) / sizeof(char*) - 1;
  br::Context::initialize(argc, argv);

  // Retrieve class for enrolling templates using the AgeEstimation algorithm
  QSharedPointer<br::Transform> transform = br::Transform::fromAlgorithm("GenderEstimation");

  // Initialize templates
  br::Template queryA((const char*)(*str));
  // br::Template queryB("/srv/node/data/b.jpg");

  // Enroll templates
  br::Globals->enrollAll = false; // Enroll exactly one face per image
  queryA >> *transform;
  // queryB >> *transform;

  br::Context::finalize();
  QString queryAGender = queryA.file.get<QString>("Gender");

  Local<String> res = String::NewFromUtf8(isolate, queryAGender.toUtf8().constData());

  // Set the return value (using the passed in
  // FunctionCallbackInfo<Value>&)
  args.GetReturnValue().Set(res);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "ageEstimation", AgeEstimation);
  NODE_SET_METHOD(exports, "genderEstimation", GenderEstimation);
}

NODE_MODULE(addon, Init)

}  // namespace addon
