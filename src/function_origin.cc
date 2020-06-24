#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(SetOrigin)
{
  Local<Function> fn = info[0].As<Function>();
  Local<Object> target = info[1].As<Object>();
  ScriptOrigin origin = fn->GetScriptOrigin();

  target->Set(Nan::New<String>("file").ToLocalChecked(), origin.ResourceName());

  target->Set(Nan::New<String>("line").ToLocalChecked(),
              Nan::New<Integer>(fn->GetScriptLineNumber()));

  target->Set(Nan::New<String>("column").ToLocalChecked(),
              Nan::New<Integer>(fn->GetScriptColumnNumber()));

  target->Set(Nan::New<String>("inferredName").ToLocalChecked(), fn->GetInferredName());
}

static void Init(Local<v8::Object> exports)
{
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(Nan::New<String>("SetOrigin").ToLocalChecked(),
               Nan::New<FunctionTemplate>(SetOrigin)->GetFunction(context).ToLocalChecked());
}

NODE_MODULE(function_origin, Init)
