################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
UIs/Wizards/Wizard_IntTrim_Ui.obj: ../UIs/Wizards/Wizard_IntTrim_Ui.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/RC_Con/uContrl/grlib_demo/drivers" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --advice:power="all" -g --gcc --define=U_CONTRL --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C1294NCPDT --define=TARGET_IS_TM4C129_RA0 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=on --abi=eabi --ual --preproc_with_compile --preproc_dependency="UIs/Wizards/Wizard_IntTrim_Ui.d" --obj_directory="UIs/Wizards" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

UIs/Wizards/Wizard_TwoChnlModl_Leaf_Ui.obj: ../UIs/Wizards/Wizard_TwoChnlModl_Leaf_Ui.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="C:/ti/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --include_path="C:/RC_Con/uContrl/grlib_demo/drivers" --include_path="C:/ti/TivaWare_C_Series-2.1.2.111" --advice:power="all" -g --gcc --define=U_CONTRL --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C1294NCPDT --define=TARGET_IS_TM4C129_RA0 --diag_wrap=off --diag_warning=225 --display_error_number --gen_func_subsections=on --abi=eabi --ual --preproc_with_compile --preproc_dependency="UIs/Wizards/Wizard_TwoChnlModl_Leaf_Ui.d" --obj_directory="UIs/Wizards" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


