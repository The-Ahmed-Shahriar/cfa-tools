OPT := # -O2
VIMPL := EXT
BCHECK := BARGINGCHECK
OUTPUT := OUTPUT

# CXX = u++					# uC++ compiler
CXX = /u/cs343/cfa-cc/bin/cfa			# CFA compiler
CXXFLAGS = -g -Wall -Wextra -multi -MMD ${OPT} -D"${VIMPL}" -D"${OUTPUT}" -D"${BCHECK}" # compiler flags
ifeq ("${OUTPUT}","NOOUTPUT")
	CXXFLAGS += -O2 -nodebug
endif
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS = q3printer.cfa.o q3tallyVotes.cfa.o q3driver.cfa.o
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXEC = vote

ifeq ($(notdir $(strip ${CXX})),cfa)
CXXFLAGS := $(filter-out -multi,${CXXFLAGS})	# remove uC++ -multi flag
CXXFLAGS += "-Wno-implicit-fallthrough"
CFA=fa
.SUFFIXES :					# remove other default suffix rules
.SUFFIXES : .cfa .o				# add CFA default rules
%.cfa.o : %.cfa
	${CXX} ${CXXFLAGS} -c $< -o $@
endif

.PHONY : all clean
.ONESHELL :

all : ${EXEC}					# build all executables

#############################################################

-include VoteImpl

# same implementation concurrency/type as last time ?
ifeq (${shell if [ "${LOCKVIMPL}" = "${VIMPL}" -a "${OUTPUTTYPE}" = "${OUTPUT}" \
		-a "${BCHECKIMPL}" = "${BCHECK}" ] ; then echo true ; fi },true)
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@
else						# implementation type has changed => rebuilt
.PHONY : ${EXEC}
${EXEC} :
	rm -f VoteImpl
	touch q3tallyVotes.h${CFA}
	${MAKE} ${EXEC} VIMPL="${VIMPL}" OUTPUT="${OUTPUT}" BCHECK="${BCHECK}"
endif

VoteImpl :
	echo "LOCKVIMPL=${VIMPL}\nOUTPUTTYPE=${OUTPUT}\nBCHECKIMPL=${BCHECK}" > VoteImpl
	sleep 1

#############################################################

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC} VoteImpl
