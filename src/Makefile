#================================ PROJECT NAME =================================
PROJECT_NAME          := maze

#==================================== FLAGS ====================================
VALGRIND              := --leak-check=full

#=============================== DIRECTORY NAMES ===============================
BIN_DIR               := ../bin
TEST_BIN_DIR          := ./test_bin
DOCS_DIR              := ../docs
DIST_DIR              := ../dist

#================================== FILE LIST ==================================
ALL_FILES             := $(shell find . -type f \( -name "*.h" -o -name "*.cc" \))
ARCHIVE_NAME          := $(PROJECT_NAME).tar.gz
GCOVR_EXCLUDES        := --exclude='.*tests/.*|.*include/.*'
GCOVR_HTML            := -r .. $(GCOVR_EXCLUDES) --html --html-details -o coverage.html 
GCOVR_TXT             := -r .. $(GCOVR_EXCLUDES) --txt -o coverage.txt

1:
	@echo $(ALL_FILES)

#=================================== TARGETS ===================================
all: install run

install: $(BIN_DIR)
	cd $(BIN_DIR) && cmake ../src && make

uninstall: clean
	rm -rf $(BIN_DIR)
	rm -rf $(DOCS_DIR)
	rm -rf $(DIST_DIR)

test: $(TEST_BIN_DIR)
	cd $(TEST_BIN_DIR) && cmake ../tests && make
	valgrind $(VALGRIND) ./$(TEST_BIN_DIR)/tests

clean:
	rm -rf $(TEST_BIN_DIR)

run:
	$(BIN_DIR)/$(PROJECT_NAME)

valgrind_run:
	valgrind $(VALGRIND) $(BIN_DIR)/$(PROJECT_NAME)

#================================ STYLE CHECKS =================================
cpplint:
	cpplint $(ALL_FILES)

clang:
	clang-format -style=Google -i $(ALL_FILES)

#============================= CREATE DIRECTORIES ==============================
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(TEST_BIN_DIR):
	mkdir -p $(TEST_BIN_DIR)

$(DOCS_DIR):
	mkdir $(DOCS_DIR)

$(DIST_DIR):
	mkdir $(DIST_DIR)

#=========================== GENERATE DOCUMENTATION ============================
dvi: $(DOCS_DIR)
	doxygen Doxyfile
	xdg-open $(DOCS_DIR)/html/index.html

#=================================== ARCHIVE ===================================
dist: clean $(DIST_DIR)
	tar -czvf $(DIST_DIR)/$(ARCHIVE_NAME) -C .. src README.md README_RUS.md LICENSE

#================================== COVERAGE ===================================
gcov_report: test
	cd $(TEST_BIN_DIR) && \
  gcovr $(GCOVR_HTML) && \
	gcovr $(GCOVR_TXT)
	xdg-open $(TEST_BIN_DIR)/coverage.html
