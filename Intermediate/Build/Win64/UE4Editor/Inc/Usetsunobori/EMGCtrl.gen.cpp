// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Usetsunobori/Public/EMGCtrl.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEMGCtrl() {}
// Cross Module References
	USETSUNOBORI_API UClass* Z_Construct_UClass_AEMGCtrl_NoRegister();
	USETSUNOBORI_API UClass* Z_Construct_UClass_AEMGCtrl();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_Usetsunobori();
// End Cross Module References
	DEFINE_FUNCTION(AEMGCtrl::execResetEMG)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_port);
		P_GET_UBOOL(Z_Param_is_high);
		P_GET_UBOOL(Z_Param_reset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetEMG(Z_Param_port,Z_Param_is_high,Z_Param_reset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEMGCtrl::execSetComPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetComPath(Z_Param_path);
		P_NATIVE_END;
	}
	static FName NAME_AEMGCtrl_EMGErrorEvt = FName(TEXT("EMGErrorEvt"));
	void AEMGCtrl::EMGErrorEvt(int32 errcode)
	{
		EMGCtrl_eventEMGErrorEvt_Parms Parms;
		Parms.errcode=errcode;
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_EMGErrorEvt),&Parms);
	}
	static FName NAME_AEMGCtrl_LHSStartEvt = FName(TEXT("LHSStartEvt"));
	void AEMGCtrl::LHSStartEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_LHSStartEvt),NULL);
	}
	static FName NAME_AEMGCtrl_LHSStopEvt = FName(TEXT("LHSStopEvt"));
	void AEMGCtrl::LHSStopEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_LHSStopEvt),NULL);
	}
	static FName NAME_AEMGCtrl_MHSStartEvt = FName(TEXT("MHSStartEvt"));
	void AEMGCtrl::MHSStartEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_MHSStartEvt),NULL);
	}
	static FName NAME_AEMGCtrl_MHSStopEvt = FName(TEXT("MHSStopEvt"));
	void AEMGCtrl::MHSStopEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_MHSStopEvt),NULL);
	}
	static FName NAME_AEMGCtrl_RHSStartEvt = FName(TEXT("RHSStartEvt"));
	void AEMGCtrl::RHSStartEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_RHSStartEvt),NULL);
	}
	static FName NAME_AEMGCtrl_RHSStopEvt = FName(TEXT("RHSStopEvt"));
	void AEMGCtrl::RHSStopEvt()
	{
		ProcessEvent(FindFunctionChecked(NAME_AEMGCtrl_RHSStopEvt),NULL);
	}
	void AEMGCtrl::StaticRegisterNativesAEMGCtrl()
	{
		UClass* Class = AEMGCtrl::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetEMG", &AEMGCtrl::execResetEMG },
			{ "SetComPath", &AEMGCtrl::execSetComPath },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_errcode_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_errcode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::NewProp_errcode_MetaData[] = {
		{ "DisplayName", "Port_n" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::NewProp_errcode = { "errcode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EMGCtrl_eventEMGErrorEvt_Parms, errcode), METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::NewProp_errcode_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::NewProp_errcode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::NewProp_errcode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Error received from EMG" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "EMGErrorEvt", nullptr, nullptr, sizeof(EMGCtrl_eventEMGErrorEvt_Parms), Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "Comment", "//virtual void Tick(float DeltaTime) override;\n" },
		{ "DisplayName", "Left hand EMG is high" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
		{ "ToolTip", "virtual void Tick(float DeltaTime) override;" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "LHSStartEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_LHSStartEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_LHSStartEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Left hand EMG is low" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "LHSStopEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_LHSStopEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_LHSStopEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Both hands EMG are high" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "MHSStartEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_MHSStartEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_MHSStartEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Both hands EMG are low" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "MHSStopEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_MHSStopEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_MHSStopEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics
	{
		struct EMGCtrl_eventResetEMG_Parms
		{
			int32 port;
			bool is_high;
			bool reset;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_port_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_port;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_is_high_MetaData[];
#endif
		static void NewProp_is_high_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_is_high;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_reset_MetaData[];
#endif
		static void NewProp_reset_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_reset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_port_MetaData[] = {
		{ "DisplayName", "Port_n" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_port = { "port", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EMGCtrl_eventResetEMG_Parms, port), METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_port_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_port_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high_MetaData[] = {
		{ "DisplayName", "is_high" },
	};
#endif
	void Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high_SetBit(void* Obj)
	{
		((EMGCtrl_eventResetEMG_Parms*)Obj)->is_high = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high = { "is_high", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EMGCtrl_eventResetEMG_Parms), &Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high_SetBit, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset_MetaData[] = {
		{ "DisplayName", "reset" },
	};
#endif
	void Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset_SetBit(void* Obj)
	{
		((EMGCtrl_eventResetEMG_Parms*)Obj)->reset = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset = { "reset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(EMGCtrl_eventResetEMG_Parms), &Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset_SetBit, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_port,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_is_high,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::NewProp_reset,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::Function_MetaDataParams[] = {
		{ "Category", "Reset" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "ResetEMG", nullptr, nullptr, sizeof(EMGCtrl_eventResetEMG_Parms), Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_ResetEMG()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_ResetEMG_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Right hand EMG is high" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "RHSStartEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_RHSStartEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_RHSStartEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "DisplayName", "Right hand EMG is low" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "RHSStopEvt", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_RHSStopEvt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_RHSStopEvt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics
	{
		struct EMGCtrl_eventSetComPath_Parms
		{
			FString path;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_path_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_path;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::NewProp_path_MetaData[] = {
		{ "DisplayName", "Path" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(EMGCtrl_eventSetComPath_Parms, path), METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::NewProp_path_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::NewProp_path_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::NewProp_path,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SetComPath" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEMGCtrl, nullptr, "SetComPath", nullptr, nullptr, sizeof(EMGCtrl_eventSetComPath_Parms), Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEMGCtrl_SetComPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEMGCtrl_SetComPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEMGCtrl_NoRegister()
	{
		return AEMGCtrl::StaticClass();
	}
	struct Z_Construct_UClass_AEMGCtrl_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEMGCtrl_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_Usetsunobori,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEMGCtrl_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEMGCtrl_EMGErrorEvt, "EMGErrorEvt" }, // 3408677126
		{ &Z_Construct_UFunction_AEMGCtrl_LHSStartEvt, "LHSStartEvt" }, // 3691353482
		{ &Z_Construct_UFunction_AEMGCtrl_LHSStopEvt, "LHSStopEvt" }, // 461716232
		{ &Z_Construct_UFunction_AEMGCtrl_MHSStartEvt, "MHSStartEvt" }, // 2100622198
		{ &Z_Construct_UFunction_AEMGCtrl_MHSStopEvt, "MHSStopEvt" }, // 1474499000
		{ &Z_Construct_UFunction_AEMGCtrl_ResetEMG, "ResetEMG" }, // 3035328238
		{ &Z_Construct_UFunction_AEMGCtrl_RHSStartEvt, "RHSStartEvt" }, // 3971224555
		{ &Z_Construct_UFunction_AEMGCtrl_RHSStopEvt, "RHSStopEvt" }, // 1404722124
		{ &Z_Construct_UFunction_AEMGCtrl_SetComPath, "SetComPath" }, // 2782237688
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEMGCtrl_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "EMGCtrl.h" },
		{ "ModuleRelativePath", "Public/EMGCtrl.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEMGCtrl_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEMGCtrl>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEMGCtrl_Statics::ClassParams = {
		&AEMGCtrl::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEMGCtrl_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEMGCtrl_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEMGCtrl()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEMGCtrl_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEMGCtrl, 3514010512);
	template<> USETSUNOBORI_API UClass* StaticClass<AEMGCtrl>()
	{
		return AEMGCtrl::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEMGCtrl(Z_Construct_UClass_AEMGCtrl, &AEMGCtrl::StaticClass, TEXT("/Script/Usetsunobori"), TEXT("AEMGCtrl"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEMGCtrl);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
