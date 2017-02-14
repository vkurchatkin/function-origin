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
  target->Set(Nan::New<String>("file").ToLocalChecked(), origin.ResourceName());

  target->Set(Nan::New<String>("line").ToLocalChecked(),
    Nan::New<Integer>(fn->GetScriptLineNumber()));

  target->Set(Nan::New<String>("column").ToLocalChecked(),
    Nan::New<Integer>(fn->GetScriptColumnNumber()));

  target->Set(Nan::New<String>("inferredName").ToLocalChecked(), fn->GetInferredName());
}

static void Init(Handle<Object> exports) {
  exports->Set(Nan::New<String>("SetOrigin").ToLocalChecked(),
    Nan::New<FunctionTemplate>(SetOrigin)->GetFunction());
}

NODE_MODULE(function_origin, Init)
