#!/bin/bash
#
# Refer to:
#   https://github.com/dylanaraps/pywal

# Set wal color scheme on load if:
#    - a cached color scheme exists and
#    - we are in an interactive shell and
#    - we are not in a login shell
#
# This to avoid setting the color scheme when ssh-ing into the
# box as well as when doing other tools like scp. 
if [ -f ~/.cache/wal/sequences ]; then
	if [[ $- == *i* ]]; then
		if [ $ZSH_VERSION ]; then
			if [[ ! -o login ]]; then
				(cat ~/.cache/wal/sequences &)
			fi
		else
			shopt -q login_shell
			if [[ $? != 0 ]]; then
				(cat ~/.cache/wal/sequences &)
			fi
		fi
	fi
fi