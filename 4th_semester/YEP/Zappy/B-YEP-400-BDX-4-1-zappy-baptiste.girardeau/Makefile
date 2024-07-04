##
## EPITECH PROJECT, 2024
## zappy
## File description:
## Makefile
##

BUILD_DIR := build
NCPUS := $(shell nproc)

SERVER_BIN := zappy_server
SERVER_SRC := $(BUILD_DIR)/server/zappy_server

GUI_BIN := zappy_gui
GUI_SRC := $(BUILD_DIR)/gui/zappy_gui

AI_BIN := zappy_ai
AI_DIR := ai

reset			:=  \033[0m
bold			:= 	\033[1m
underline		:= 	\033[4m
green			:=  \033[32m
blue			:= 	\033[34m
grey 			:= 	\033[90m

all: release

.PHONY: release
release: build-release copy ## Build with release mode

.PHONY: debug
debug: build-debug copy ## Build with debug mode

.PHONY: asan
asan: build-asan copy ## Build with address sanitizer

.PHONY: tsan
tsan: build-tsan copy ## Build with thread sanitizer

.PHONY: build
build-release:
	@printf "$(build)$(grey)Building with CMake...$(reset)\n"
	cmake -B $(BUILD_DIR) -S . -DCMAKE_BUILD_TYPE=Release -DSANITIZER=NONE
	cmake --build $(BUILD_DIR) -j $(NCPUS)

.PHONY: build-debug
build-debug:
	@printf "$(build)$(grey)Building with CMake (debug)...$(reset)\n"
	cmake -B $(BUILD_DIR) -S . -DCMAKE_BUILD_TYPE=Debug -DSANITIZER=NONE
	cmake --build $(BUILD_DIR) -j $(NCPUS)

.PHONY: build-asan
build-asan:
	@printf "$(build)$(grey)Building with CMake (asan)...$(reset)\n"
	cmake -B $(BUILD_DIR) -S . -DCMAKE_BUILD_TYPE=Debug -DSANITIZER=MEMORY
	cmake --build $(BUILD_DIR) -j $(NCPUS)

.PHONY: build-tsan
build-tsan:
	@printf "$(build)$(grey)Building with CMake (tsan)...$(reset)\n"
	cmake -B $(BUILD_DIR) -S . -DCMAKE_BUILD_TYPE=Debug -DSANITIZER=THREAD
	cmake --build $(BUILD_DIR) -j $(NCPUS)

## COPY ##

.PHONY: copy
copy: $(SERVER_BIN) $(GUI_BIN) $(AI_BIN)

$(SERVER_BIN): $(SERVER_SRC)
	@cp $< $@
	@printf "$(bold)$(green)Copied $(SERVER_BIN)$(reset)\n"

$(GUI_BIN): $(GUI_SRC)
	@cp $< $@
	@printf "$(bold)$(green)Copied $(GUI_BIN)$(reset)\n"

$(AI_BIN):
	@printf "#!/usr/bin/sh\npython3 -m ai \"\$$@\"\n" > $@
	@chmod +x $@
	@printf "$(bold)$(green)Copied $(AI_BIN)$(reset)\n"

## TOOLS ##

.PHONY: format
format: ## Format with clang-format
	@printf "$(build)$(grey)Formatting with clang-format...$(reset)\n"
	fd --glob "*.{cpp,hpp}" --exec-batch clang-format -i -style=file

# https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.PHONY: help
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = ":.*?## "}; \
	{printf "$(blue)$(bold)%-30s$(reset) %s\n", $$1, $$2}'

## CLEAN ##

.PHONY: clean
clean: ## Clean build directory
	@printf "$(build)$(grey)Cleaning...$(reset)\n"
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean ## Clean build directory and binaries
	$(RM) $(SERVER_BIN)
	$(RM) $(GUI_BIN)
	$(RM) $(AI_BIN)

.PHONY: re
re: fclean all ## Rebuild everything
