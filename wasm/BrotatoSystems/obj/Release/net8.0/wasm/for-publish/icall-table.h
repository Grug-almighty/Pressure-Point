#define ICALL_TABLE_corlib 1

static int corlib_icall_indexes [] = {
128,
136,
137,
138,
139,
140,
141,
142,
144,
145,
176,
177,
178,
196,
197,
200,
201,
202,
203,
263,
264,
266,
296,
297,
299,
301,
303,
305,
310,
318,
319,
320,
321,
322,
323,
396,
397,
448,
453,
456,
458,
463,
464,
466,
467,
471,
472,
474,
476,
477,
480,
481,
482,
485,
487,
489,
491,
500,
552,
554,
556,
566,
567,
568,
570,
576,
577,
578,
579,
580,
588,
589,
590,
594,
595,
597,
599,
720,
864,
865,
4102,
4103,
4105,
4106,
4107,
4108,
4110,
4112,
4114,
4119,
4121,
4125,
4127,
4129,
4180,
4181,
4183,
4184,
4185,
4186,
4187,
4189,
4191,
4674,
4677,
4679,
4680,
4681,
4869,
4870,
4871,
4872,
4888,
4889,
4890,
4972,
4974,
4984,
4985,
4986,
4987,
5114,
5116,
5136,
5150,
5156,
5163,
5174,
5177,
5193,
5265,
5267,
5273,
5281,
5299,
5300,
5308,
5310,
5316,
5317,
5320,
5324,
5330,
5331,
5338,
5340,
5351,
5354,
5355,
5356,
5366,
5374,
5379,
5380,
5381,
5397,
5399,
5411,
5447,
5469,
5470,
5855,
5908,
5909,
6039,
6040,
6044,
6047,
6103,
6411,
6421,
6750,
6771,
6773,
6775,
};
void ves_icall_System_Array_InternalCreate (int,int,int,int,int);
int ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal (int);
int ves_icall_System_Array_CanChangePrimitive (int,int,int);
int ves_icall_System_Array_FastCopy (int,int,int,int,int);
int ves_icall_System_Array_GetLengthInternal_raw (int,int,int);
int ves_icall_System_Array_GetLowerBoundInternal_raw (int,int,int);
void ves_icall_System_Array_GetGenericValue_icall (int,int,int);
void ves_icall_System_Array_GetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetValueRelaxedImpl_raw (int,int,int,int);
void ves_icall_System_Runtime_RuntimeImports_ZeroMemory (int,int);
void ves_icall_System_Runtime_RuntimeImports_Memmove (int,int,int);
void ves_icall_System_Buffer_BulkMoveWithWriteBarrier (int,int,int,int);
int ves_icall_System_Delegate_CreateDelegate_internal_raw (int,int,int,int,int);
int ves_icall_System_Delegate_GetVirtualMethod_internal_raw (int,int);
void ves_icall_System_Enum_GetEnumValuesAndNames_raw (int,int,int,int);
void ves_icall_System_Enum_InternalBoxEnum_raw (int,int,int64_t,int);
int ves_icall_System_Enum_InternalGetCorElementType (int);
void ves_icall_System_Enum_InternalGetUnderlyingType_raw (int,int,int);
int ves_icall_System_Environment_get_ProcessorCount ();
int ves_icall_System_Environment_get_TickCount ();
void ves_icall_System_Environment_FailFast_raw (int,int,int,int);
void ves_icall_System_GC_register_ephemeron_array_raw (int,int);
int ves_icall_System_GC_get_ephemeron_tombstone_raw (int);
void ves_icall_System_GC_SuppressFinalize_raw (int,int);
void ves_icall_System_GC_ReRegisterForFinalize_raw (int,int);
void ves_icall_System_GC_GetGCMemoryInfo (int,int,int,int,int,int);
int ves_icall_System_GC_AllocPinnedArray_raw (int,int,int);
int ves_icall_System_Object_MemberwiseClone_raw (int,int);
double ves_icall_System_Math_Ceiling (double);
double ves_icall_System_Math_Floor (double);
double ves_icall_System_Math_Log10 (double);
double ves_icall_System_Math_Pow (double,double);
double ves_icall_System_Math_Sqrt (double);
double ves_icall_System_Math_ModF (double,int);
void ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw (int,int,int);
void ves_icall_RuntimeMethodHandle_ReboxToNullable_raw (int,int,int,int);
int ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw (int,int,int);
void ves_icall_RuntimeType_make_array_type_raw (int,int,int,int);
void ves_icall_RuntimeType_make_byref_type_raw (int,int,int);
void ves_icall_RuntimeType_make_pointer_type_raw (int,int,int);
void ves_icall_RuntimeType_MakeGenericType_raw (int,int,int,int);
int ves_icall_RuntimeType_GetMethodsByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetPropertiesByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetConstructors_native_raw (int,int,int);
int ves_icall_System_RuntimeType_CreateInstanceInternal_raw (int,int);
void ves_icall_System_RuntimeType_AllocateValueType_raw (int,int,int,int);
void ves_icall_RuntimeType_GetDeclaringMethod_raw (int,int,int);
void ves_icall_System_RuntimeType_getFullName_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetGenericArgumentsInternal_raw (int,int,int,int);
int ves_icall_RuntimeType_GetGenericParameterPosition (int);
int ves_icall_RuntimeType_GetEvents_native_raw (int,int,int,int);
int ves_icall_RuntimeType_GetFields_native_raw (int,int,int,int,int);
void ves_icall_RuntimeType_GetInterfaces_raw (int,int,int);
void ves_icall_RuntimeType_GetDeclaringType_raw (int,int,int);
void ves_icall_RuntimeType_GetName_raw (int,int,int);
void ves_icall_RuntimeType_GetNamespace_raw (int,int,int);
int ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetAttributes (int);
int ves_icall_RuntimeTypeHandle_GetMetadataToken_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_GetCorElementType (int);
int ves_icall_RuntimeTypeHandle_HasInstantiation (int);
int ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_HasReferences_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetArrayRank_raw (int,int);
void ves_icall_RuntimeTypeHandle_GetAssembly_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetElementType_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetModule_raw (int,int,int);
void ves_icall_RuntimeTypeHandle_GetBaseType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition (int);
int ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw (int,int);
int ves_icall_RuntimeTypeHandle_is_subclass_of_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsByRefLike_raw (int,int);
void ves_icall_System_RuntimeTypeHandle_internal_from_name_raw (int,int,int,int,int,int);
int ves_icall_System_String_FastAllocateString_raw (int,int);
int ves_icall_System_Type_internal_from_handle_raw (int,int);
int ves_icall_System_ValueType_InternalGetHashCode_raw (int,int,int);
int ves_icall_System_ValueType_Equals_raw (int,int,int,int);
int ves_icall_System_Threading_Interlocked_CompareExchange_Int (int,int,int);
void ves_icall_System_Threading_Interlocked_CompareExchange_Object (int,int,int,int);
int ves_icall_System_Threading_Interlocked_Decrement_Int (int);
int ves_icall_System_Threading_Interlocked_Increment_Int (int);
int ves_icall_System_Threading_Interlocked_Exchange_Int (int,int);
void ves_icall_System_Threading_Interlocked_Exchange_Object (int,int,int);
int64_t ves_icall_System_Threading_Interlocked_CompareExchange_Long (int,int64_t,int64_t);
int64_t ves_icall_System_Threading_Interlocked_Exchange_Long (int,int64_t);
int ves_icall_System_Threading_Interlocked_Add_Int (int,int);
void ves_icall_System_Threading_Monitor_Monitor_Enter_raw (int,int);
void mono_monitor_exit_icall_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw (int,int);
int ves_icall_System_Threading_Monitor_Monitor_wait_raw (int,int,int,int);
void ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw (int,int,int,int,int);
void ves_icall_System_Threading_Thread_InitInternal_raw (int,int);
int ves_icall_System_Threading_Thread_GetCurrentThread ();
void ves_icall_System_Threading_InternalThread_Thread_free_internal_raw (int,int);
int ves_icall_System_Threading_Thread_GetState_raw (int,int);
void ves_icall_System_Threading_Thread_SetState_raw (int,int,int);
void ves_icall_System_Threading_Thread_ClrState_raw (int,int,int);
void ves_icall_System_Threading_Thread_SetName_icall_raw (int,int,int,int);
int ves_icall_System_Threading_Thread_YieldInternal ();
void ves_icall_System_Threading_Thread_SetPriority_raw (int,int,int);
void ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw (int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw (int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw (int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw (int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw (int,int,int,int,int,int);
int ves_icall_System_GCHandle_InternalAlloc_raw (int,int,int);
void ves_icall_System_GCHandle_InternalFree_raw (int,int);
int ves_icall_System_GCHandle_InternalGet_raw (int,int);
void ves_icall_System_GCHandle_InternalSet_raw (int,int,int);
int ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError ();
void ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError (int);
void ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw (int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalTryGetHashCode_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw (int,int);
void ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw (int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw (int,int,int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack ();
int ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw (int);
int ves_icall_System_Reflection_Assembly_InternalLoad_raw (int,int,int,int);
int ves_icall_System_Reflection_AssemblyName_GetNativeName (int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw (int,int,int,int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw (int,int);
int ves_icall_MonoCustomAttrs_IsDefinedInternal_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw (int,int);
int ves_icall_System_Reflection_LoaderAllocatorScout_Destroy (int);
void ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw (int,int,int,int);
void ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw (int,int,int);
void ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw (int,int,int,int,int,int,int);
void ves_icall_RuntimeEventInfo_get_event_info_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_ResolveType_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetParentType_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetFieldOffset_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetValueInternal_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_get_method_info_raw (int,int,int);
int ves_icall_get_method_attributes (int);
int ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw (int,int,int);
int ves_icall_System_MonoMethodInfo_get_retval_marshal_raw (int,int);
int ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw (int,int,int,int);
int ves_icall_RuntimeMethodInfo_get_name_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_base_method_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
void ves_icall_RuntimeMethodInfo_GetPInvoke_raw (int,int,int,int,int);
int ves_icall_RuntimeMethodInfo_GetGenericArguments_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw (int,int);
void ves_icall_InvokeClassConstructor_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_RuntimePropertyInfo_get_property_info_raw (int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw (int,int,int);
void ves_icall_DynamicMethod_create_dynamic_method_raw (int,int,int,int,int);
void ves_icall_AssemblyBuilder_basic_init_raw (int,int);
void ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw (int,int);
void ves_icall_ModuleBuilder_basic_init_raw (int,int);
void ves_icall_ModuleBuilder_set_wrappers_type_raw (int,int,int);
int ves_icall_ModuleBuilder_getToken_raw (int,int,int,int);
void ves_icall_ModuleBuilder_RegisterToken_raw (int,int,int,int);
int ves_icall_TypeBuilder_create_runtime_class_raw (int,int);
int ves_icall_System_Diagnostics_StackFrame_GetFrameInfo (int,int,int,int,int,int,int,int);
void ves_icall_System_Diagnostics_StackTrace_GetTrace (int,int,int,int);
int ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass (int);
void ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree (int);
int ves_icall_Mono_SafeStringMarshal_StringToUtf8 (int);
void ves_icall_Mono_SafeStringMarshal_GFree (int);
static void *corlib_icall_funcs [] = {
// token 128,
ves_icall_System_Array_InternalCreate,
// token 136,
ves_icall_System_Array_GetCorElementTypeOfElementTypeInternal,
// token 137,
ves_icall_System_Array_CanChangePrimitive,
// token 138,
ves_icall_System_Array_FastCopy,
// token 139,
ves_icall_System_Array_GetLengthInternal_raw,
// token 140,
ves_icall_System_Array_GetLowerBoundInternal_raw,
// token 141,
ves_icall_System_Array_GetGenericValue_icall,
// token 142,
ves_icall_System_Array_GetValueImpl_raw,
// token 144,
ves_icall_System_Array_SetValueImpl_raw,
// token 145,
ves_icall_System_Array_SetValueRelaxedImpl_raw,
// token 176,
ves_icall_System_Runtime_RuntimeImports_ZeroMemory,
// token 177,
ves_icall_System_Runtime_RuntimeImports_Memmove,
// token 178,
ves_icall_System_Buffer_BulkMoveWithWriteBarrier,
// token 196,
ves_icall_System_Delegate_CreateDelegate_internal_raw,
// token 197,
ves_icall_System_Delegate_GetVirtualMethod_internal_raw,
// token 200,
ves_icall_System_Enum_GetEnumValuesAndNames_raw,
// token 201,
ves_icall_System_Enum_InternalBoxEnum_raw,
// token 202,
ves_icall_System_Enum_InternalGetCorElementType,
// token 203,
ves_icall_System_Enum_InternalGetUnderlyingType_raw,
// token 263,
ves_icall_System_Environment_get_ProcessorCount,
// token 264,
ves_icall_System_Environment_get_TickCount,
// token 266,
ves_icall_System_Environment_FailFast_raw,
// token 296,
ves_icall_System_GC_register_ephemeron_array_raw,
// token 297,
ves_icall_System_GC_get_ephemeron_tombstone_raw,
// token 299,
ves_icall_System_GC_SuppressFinalize_raw,
// token 301,
ves_icall_System_GC_ReRegisterForFinalize_raw,
// token 303,
ves_icall_System_GC_GetGCMemoryInfo,
// token 305,
ves_icall_System_GC_AllocPinnedArray_raw,
// token 310,
ves_icall_System_Object_MemberwiseClone_raw,
// token 318,
ves_icall_System_Math_Ceiling,
// token 319,
ves_icall_System_Math_Floor,
// token 320,
ves_icall_System_Math_Log10,
// token 321,
ves_icall_System_Math_Pow,
// token 322,
ves_icall_System_Math_Sqrt,
// token 323,
ves_icall_System_Math_ModF,
// token 396,
ves_icall_RuntimeMethodHandle_ReboxFromNullable_raw,
// token 397,
ves_icall_RuntimeMethodHandle_ReboxToNullable_raw,
// token 448,
ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw,
// token 453,
ves_icall_RuntimeType_make_array_type_raw,
// token 456,
ves_icall_RuntimeType_make_byref_type_raw,
// token 458,
ves_icall_RuntimeType_make_pointer_type_raw,
// token 463,
ves_icall_RuntimeType_MakeGenericType_raw,
// token 464,
ves_icall_RuntimeType_GetMethodsByName_native_raw,
// token 466,
ves_icall_RuntimeType_GetPropertiesByName_native_raw,
// token 467,
ves_icall_RuntimeType_GetConstructors_native_raw,
// token 471,
ves_icall_System_RuntimeType_CreateInstanceInternal_raw,
// token 472,
ves_icall_System_RuntimeType_AllocateValueType_raw,
// token 474,
ves_icall_RuntimeType_GetDeclaringMethod_raw,
// token 476,
ves_icall_System_RuntimeType_getFullName_raw,
// token 477,
ves_icall_RuntimeType_GetGenericArgumentsInternal_raw,
// token 480,
ves_icall_RuntimeType_GetGenericParameterPosition,
// token 481,
ves_icall_RuntimeType_GetEvents_native_raw,
// token 482,
ves_icall_RuntimeType_GetFields_native_raw,
// token 485,
ves_icall_RuntimeType_GetInterfaces_raw,
// token 487,
ves_icall_RuntimeType_GetDeclaringType_raw,
// token 489,
ves_icall_RuntimeType_GetName_raw,
// token 491,
ves_icall_RuntimeType_GetNamespace_raw,
// token 500,
ves_icall_RuntimeType_FunctionPointerReturnAndParameterTypes_raw,
// token 552,
ves_icall_RuntimeTypeHandle_GetAttributes,
// token 554,
ves_icall_RuntimeTypeHandle_GetMetadataToken_raw,
// token 556,
ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw,
// token 566,
ves_icall_RuntimeTypeHandle_GetCorElementType,
// token 567,
ves_icall_RuntimeTypeHandle_HasInstantiation,
// token 568,
ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw,
// token 570,
ves_icall_RuntimeTypeHandle_HasReferences_raw,
// token 576,
ves_icall_RuntimeTypeHandle_GetArrayRank_raw,
// token 577,
ves_icall_RuntimeTypeHandle_GetAssembly_raw,
// token 578,
ves_icall_RuntimeTypeHandle_GetElementType_raw,
// token 579,
ves_icall_RuntimeTypeHandle_GetModule_raw,
// token 580,
ves_icall_RuntimeTypeHandle_GetBaseType_raw,
// token 588,
ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw,
// token 589,
ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition,
// token 590,
ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw,
// token 594,
ves_icall_RuntimeTypeHandle_is_subclass_of_raw,
// token 595,
ves_icall_RuntimeTypeHandle_IsByRefLike_raw,
// token 597,
ves_icall_System_RuntimeTypeHandle_internal_from_name_raw,
// token 599,
ves_icall_System_String_FastAllocateString_raw,
// token 720,
ves_icall_System_Type_internal_from_handle_raw,
// token 864,
ves_icall_System_ValueType_InternalGetHashCode_raw,
// token 865,
ves_icall_System_ValueType_Equals_raw,
// token 4102,
ves_icall_System_Threading_Interlocked_CompareExchange_Int,
// token 4103,
ves_icall_System_Threading_Interlocked_CompareExchange_Object,
// token 4105,
ves_icall_System_Threading_Interlocked_Decrement_Int,
// token 4106,
ves_icall_System_Threading_Interlocked_Increment_Int,
// token 4107,
ves_icall_System_Threading_Interlocked_Exchange_Int,
// token 4108,
ves_icall_System_Threading_Interlocked_Exchange_Object,
// token 4110,
ves_icall_System_Threading_Interlocked_CompareExchange_Long,
// token 4112,
ves_icall_System_Threading_Interlocked_Exchange_Long,
// token 4114,
ves_icall_System_Threading_Interlocked_Add_Int,
// token 4119,
ves_icall_System_Threading_Monitor_Monitor_Enter_raw,
// token 4121,
mono_monitor_exit_icall_raw,
// token 4125,
ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw,
// token 4127,
ves_icall_System_Threading_Monitor_Monitor_wait_raw,
// token 4129,
ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw,
// token 4180,
ves_icall_System_Threading_Thread_InitInternal_raw,
// token 4181,
ves_icall_System_Threading_Thread_GetCurrentThread,
// token 4183,
ves_icall_System_Threading_InternalThread_Thread_free_internal_raw,
// token 4184,
ves_icall_System_Threading_Thread_GetState_raw,
// token 4185,
ves_icall_System_Threading_Thread_SetState_raw,
// token 4186,
ves_icall_System_Threading_Thread_ClrState_raw,
// token 4187,
ves_icall_System_Threading_Thread_SetName_icall_raw,
// token 4189,
ves_icall_System_Threading_Thread_YieldInternal,
// token 4191,
ves_icall_System_Threading_Thread_SetPriority_raw,
// token 4674,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw,
// token 4677,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw,
// token 4679,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw,
// token 4680,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw,
// token 4681,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw,
// token 4869,
ves_icall_System_GCHandle_InternalAlloc_raw,
// token 4870,
ves_icall_System_GCHandle_InternalFree_raw,
// token 4871,
ves_icall_System_GCHandle_InternalGet_raw,
// token 4872,
ves_icall_System_GCHandle_InternalSet_raw,
// token 4888,
ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError,
// token 4889,
ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError,
// token 4890,
ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw,
// token 4972,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalGetHashCode_raw,
// token 4974,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InternalTryGetHashCode_raw,
// token 4984,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw,
// token 4985,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw,
// token 4986,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetSpanDataFrom_raw,
// token 4987,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack,
// token 5114,
ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw,
// token 5116,
ves_icall_System_Reflection_Assembly_InternalLoad_raw,
// token 5136,
ves_icall_System_Reflection_AssemblyName_GetNativeName,
// token 5150,
ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw,
// token 5156,
ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw,
// token 5163,
ves_icall_MonoCustomAttrs_IsDefinedInternal_raw,
// token 5174,
ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw,
// token 5177,
ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw,
// token 5193,
ves_icall_System_Reflection_LoaderAllocatorScout_Destroy,
// token 5265,
ves_icall_System_Reflection_RuntimeAssembly_GetInfo_raw,
// token 5267,
ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw,
// token 5273,
ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw,
// token 5281,
ves_icall_RuntimeEventInfo_get_event_info_raw,
// token 5299,
ves_icall_reflection_get_token_raw,
// token 5300,
ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw,
// token 5308,
ves_icall_RuntimeFieldInfo_ResolveType_raw,
// token 5310,
ves_icall_RuntimeFieldInfo_GetParentType_raw,
// token 5316,
ves_icall_RuntimeFieldInfo_GetFieldOffset_raw,
// token 5317,
ves_icall_RuntimeFieldInfo_GetValueInternal_raw,
// token 5320,
ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw,
// token 5324,
ves_icall_reflection_get_token_raw,
// token 5330,
ves_icall_get_method_info_raw,
// token 5331,
ves_icall_get_method_attributes,
// token 5338,
ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw,
// token 5340,
ves_icall_System_MonoMethodInfo_get_retval_marshal_raw,
// token 5351,
ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw,
// token 5354,
ves_icall_RuntimeMethodInfo_get_name_raw,
// token 5355,
ves_icall_RuntimeMethodInfo_get_base_method_raw,
// token 5356,
ves_icall_reflection_get_token_raw,
// token 5366,
ves_icall_InternalInvoke_raw,
// token 5374,
ves_icall_RuntimeMethodInfo_GetPInvoke_raw,
// token 5379,
ves_icall_RuntimeMethodInfo_GetGenericArguments_raw,
// token 5380,
ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw,
// token 5381,
ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw,
// token 5397,
ves_icall_InvokeClassConstructor_raw,
// token 5399,
ves_icall_InternalInvoke_raw,
// token 5411,
ves_icall_reflection_get_token_raw,
// token 5447,
ves_icall_RuntimePropertyInfo_get_property_info_raw,
// token 5469,
ves_icall_reflection_get_token_raw,
// token 5470,
ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw,
// token 5855,
ves_icall_DynamicMethod_create_dynamic_method_raw,
// token 5908,
ves_icall_AssemblyBuilder_basic_init_raw,
// token 5909,
ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw,
// token 6039,
ves_icall_ModuleBuilder_basic_init_raw,
// token 6040,
ves_icall_ModuleBuilder_set_wrappers_type_raw,
// token 6044,
ves_icall_ModuleBuilder_getToken_raw,
// token 6047,
ves_icall_ModuleBuilder_RegisterToken_raw,
// token 6103,
ves_icall_TypeBuilder_create_runtime_class_raw,
// token 6411,
ves_icall_System_Diagnostics_StackFrame_GetFrameInfo,
// token 6421,
ves_icall_System_Diagnostics_StackTrace_GetTrace,
// token 6750,
ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass,
// token 6771,
ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree,
// token 6773,
ves_icall_Mono_SafeStringMarshal_StringToUtf8,
// token 6775,
ves_icall_Mono_SafeStringMarshal_GFree,
};
static uint8_t corlib_icall_flags [] = {
0,
0,
0,
0,
4,
4,
0,
4,
4,
4,
0,
0,
0,
4,
4,
4,
4,
0,
4,
0,
0,
4,
4,
4,
4,
4,
0,
4,
4,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
0,
0,
0,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
4,
4,
4,
4,
4,
4,
0,
4,
4,
0,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
4,
0,
0,
0,
0,
0,
0,
};
