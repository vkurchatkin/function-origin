#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(SetOrigin) {
  Local<Function> fn = info[0].As<Function>();
  Local<Object> target = info[1].As<Object>();

  // For bound functions the returned resource name is empty and line and
  // column numbers are meaningless.
  // In this case we keep the inferredName of the bound function, but
  // get all other information from the function from which the
  // bound function was created.
  Local<Value> bound;
  while (true) {
    bound = fn->GetBoundFunction();
    if (bound->IsFunction()) {
      fn = bound.As<Function>();
    } else {
      break;
    }
  }

  ScriptOrigin origin = fn->GetScriptOrigin();


  Nan::Set(target, Nan::New<String>("file").ToLocalChecked(), origin.ResourceName()).Check();

  Nan::Set(target, Nan::New<String>("line").ToLocalChecked(),
              Nan::New<Integer>(fn->GetScriptLineNumber())).Check();

  Nan::Set(target, Nan::New<String>("column").ToLocalChecked(),
              Nan::New<Integer>(fn->GetScriptColumnNumber())).Check();;

  Nan::Set(target, Nan::New<String>("inferredName").ToLocalChecked(), fn->GetInferredName()).Check();
}

static void Init(Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  Nan::Set(exports, Nan::New<String>("SetOrigin").ToLocalChecked(),
               Nan::New<FunctionTemplate>(SetOrigin)->GetFunction(context).ToLocalChecked()).Check();
}

NODE_MODULE(function_origin, Init)
