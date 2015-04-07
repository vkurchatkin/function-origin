#include <node.h>
#include <nan.h>

using namespace v8;

NAN_METHOD(SetOrigin) {
  NanScope();

  Local<Function> fn = args[0].As<Function>();
  Local<Object> target = args[1].As<Object>();
  ScriptOrigin origin = fn->GetScriptOrigin();

  target->Set(NanNew<String>("file"), origin.ResourceName());

  target->Set(NanNew<String>("line"),
    NanNew<Integer>(fn->GetScriptLineNumber()));

  target->Set(NanNew<String>("column"),
    NanNew<Integer>(fn->GetScriptColumnNumber()));

#if NODE_MODULE_VERSION >= NODE_0_12_MODULE_VERSION
  target->Set(NanNew<String>("scriptId"),
    NanNew<Integer>(fn->ScriptId()));
#endif

  NanReturnUndefined();
}

static void Init(Handle<Object> exports) {
  exports->Set(NanNew<String>("SetOrigin"),
    NanNew<FunctionTemplate>(SetOrigin)->GetFunction());
}

NODE_MODULE(function_origin, Init)
