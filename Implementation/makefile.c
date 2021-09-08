PROJ_NAME = bill_proj
TEST_PROJ_NAME = Test_$(bill_proj)

SRC = src/bill.c \
src/election.c  


bill_proj_SRC = test.c
TEST_SRC = test/test.c \
unity/unity.c 
INC_H = inc
INC_T = unity

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:
	gcc -I $(INC_H) $(SRC) main.c -o $(call FixPath,$(bill_proj).$(EXEC))
	
run:
	$(call FixPath,$(bill_proj).$(EXEC))
test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_bill_PROJ).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

coverage:
	cp test/test.c .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c test.c $(SRC) -o $(call FixPath, $(TEST_bill_PROJ).$(EXEC))
	$(call FixPath, ./$(TEST_bill_PROJ).$(EXEC))
	gcov -a $(bill_proj_SRC)
	$(RM) *.$(EXEC)
	
	
	$(RM) test.c


cppcheck:
	cppcheck --enable=all $(SRC) main.c
debug:
	gcc -I $(INC_H) $(SRC) main.c -g -o $(bill_PROJ).$(EXEC)
	gdb $(bill_PROJ).$(EXEC)

valgrind:
	valgrind ./$(TEST_bill_PROJ).$(EXEC)


clean:
	
	$(RM) *.$(EXEC)