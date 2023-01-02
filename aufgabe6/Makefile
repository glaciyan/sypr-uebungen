PACKAGES = lib bin
MAKE = make

.PHONY: all clean

all clean:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done