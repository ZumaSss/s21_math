CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
CFLAGS1 = -Wall -Wextra -Werror
LDFLAGS = $(shell pkg-config --cflags --libs check)

SOURCES = tests.c
EXECUTABLE = tests
TEST_FLAGS = --coverage $(LDFLAGS)

FUNC_DIR = lib_functions
OBJ_DIR = lib_functions
GCOV_DIR = report
GCOV_OBJ_DIR = obj/$(GCOV_DIR)
PWD = $(shell pwd)

SRCS = $(shell find $(PWD)/$(FUNC_DIR) -maxdepth 1 -iname '*.c')
OBJSNAME = $(shell basename -a $(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJSNAME:.c=.o))

OS := $(shell uname -s)
ifeq ($(OS), Linux)
      TEST_FLAGS += -lsubunit -lm
	#   LDFLAGS += -lsubunit
      OPEN = echo 'report: ./src/$(GCOV_DIR)/index.html'
else
      OPEN = open ./$(GCOV_DIR)/index.html
endif

all: clean s21_math.a

./$(OBJ_DIR)/%.o:%.c
	$(CC) $(CFLAGS) $< -o $@

./$(OBJ_DIR)/%.o:*/%.c
	$(CC) $(CFLAGS) $< -o $@

s21_math.a: $(OBJS)
	ar rcs $@ $^
	ranlib s21_math.a 

test:
	make s21_math.a
	make check
	$(CC) $(CFLAGS1) $(SOURCES) s21_math.a -o $(EXECUTABLE) $(LDFLAGS)
	./$(EXECUTABLE)

gcov_report:
	make clean
	make check
	mkdir -p $(GCOV_DIR)
	$(CC) $(SRCS) $(SOURCES) -o greport $(TEST_FLAGS)
	./greport
	lcov -t "s21_math" -o s21_math.info -c -d .
	genhtml -o ./$(GCOV_DIR) s21_math.info
	$(OPEN)

check:
	checkmk clean_mode=1 test_check/headers/*.check test_check/*.check test_check/main_pre/*.check > $(SOURCES)
	cp -f ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.c *.h
	rm .clang-format

rebuild: clean all

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(EXECUTABLE) $(SOURCES)
	rm -rf s21_math.a
	rm -rf *.gcda *.gcno *.info $(GCOV_DIR) check_s21_math.c greport
