##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=reservation_system
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/cworkspace/cworkspace
ProjectPath            :=D:/cworkspace/cworkspace/reservation_system
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Admin
Date                   :=11/07/2023
CodeLitePath           :=D:/CodeLite
LinkerName             :=D:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=D:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="reservation_system.txt"
PCHCompileFlags        :=
MakeDirCommand         :=D:/CodeLite/mkdir.exe -p
RcCmpOptions           := 
RcCompilerName         :=D:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := D:/TDM-GCC-64/bin/ar.exe -r
CXX      := D:/TDM-GCC-64/bin/g++.exe
CC       := D:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -gdwarf-2 -std=c++20 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\CodeLite
Objects0=$(IntermediateDirectory)/Teacher.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/OrderFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/Student.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Teacher.cpp$(ObjectSuffix): Teacher.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/cworkspace/cworkspace/reservation_system/Teacher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Teacher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Teacher.cpp$(PreprocessSuffix): Teacher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Teacher.cpp$(PreprocessSuffix) Teacher.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/cworkspace/cworkspace/reservation_system/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Manager.cpp$(ObjectSuffix): Manager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/cworkspace/cworkspace/reservation_system/Manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Manager.cpp$(PreprocessSuffix): Manager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Manager.cpp$(PreprocessSuffix) Manager.cpp

$(IntermediateDirectory)/OrderFile.cpp$(ObjectSuffix): OrderFile.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/cworkspace/cworkspace/reservation_system/OrderFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OrderFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OrderFile.cpp$(PreprocessSuffix): OrderFile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OrderFile.cpp$(PreprocessSuffix) OrderFile.cpp

$(IntermediateDirectory)/Student.cpp$(ObjectSuffix): Student.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/cworkspace/cworkspace/reservation_system/Student.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Student.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Student.cpp$(PreprocessSuffix): Student.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Student.cpp$(PreprocessSuffix) Student.cpp

##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


