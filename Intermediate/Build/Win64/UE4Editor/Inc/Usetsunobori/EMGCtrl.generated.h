// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef USETSUNOBORI_EMGCtrl_generated_h
#error "EMGCtrl.generated.h already included, missing '#pragma once' in EMGCtrl.h"
#endif
#define USETSUNOBORI_EMGCtrl_generated_h

#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_SPARSE_DATA
#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResetEMG); \
	DECLARE_FUNCTION(execSetComPath);


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetEMG); \
	DECLARE_FUNCTION(execSetComPath);


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_EVENT_PARMS \
	struct EMGCtrl_eventEMGErrorEvt_Parms \
	{ \
		int32 errcode; \
	};


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_CALLBACK_WRAPPERS
#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEMGCtrl(); \
	friend struct Z_Construct_UClass_AEMGCtrl_Statics; \
public: \
	DECLARE_CLASS(AEMGCtrl, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Usetsunobori"), NO_API) \
	DECLARE_SERIALIZER(AEMGCtrl)


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAEMGCtrl(); \
	friend struct Z_Construct_UClass_AEMGCtrl_Statics; \
public: \
	DECLARE_CLASS(AEMGCtrl, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Usetsunobori"), NO_API) \
	DECLARE_SERIALIZER(AEMGCtrl)


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEMGCtrl(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEMGCtrl) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEMGCtrl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEMGCtrl); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEMGCtrl(AEMGCtrl&&); \
	NO_API AEMGCtrl(const AEMGCtrl&); \
public:


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEMGCtrl(AEMGCtrl&&); \
	NO_API AEMGCtrl(const AEMGCtrl&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEMGCtrl); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEMGCtrl); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEMGCtrl)


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_PRIVATE_PROPERTY_OFFSET
#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_12_PROLOG \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_EVENT_PARMS


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_PRIVATE_PROPERTY_OFFSET \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_SPARSE_DATA \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_RPC_WRAPPERS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_CALLBACK_WRAPPERS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_INCLASS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_PRIVATE_PROPERTY_OFFSET \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_SPARSE_DATA \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_CALLBACK_WRAPPERS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_INCLASS_NO_PURE_DECLS \
	usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> USETSUNOBORI_API UClass* StaticClass<class AEMGCtrl>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID usetsunobori_master_Source_Usetsunobori_Public_EMGCtrl_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
