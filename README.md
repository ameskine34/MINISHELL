📖 About the Project:

Minishell is a  project that introduces you to the world of command-line interpreters.
You will implement your own shell, giving you deeper insight into:

Parsing and tokenizing user input.

Handling processes and file descriptors.

Implementing UNIX built-in commands.

Managing environment variables.

Signal handling and interactive terminal behavior.

🚀 Features :

Execute commands found in PATH.

Support for pipes (|) to connect commands.

Input (<) and output (> / >>) redirections.

Environment variables expansion ($VAR).

Quoting rules:

Single quotes "'" prevent variable expansion.

Double quotes '"' allow expansion.

Correct handling of Ctrl-C, Ctrl-D, and Ctrl-\.

Exit status management ($?).

Built-in commands implemented directly in the shell.

🔧 Builtins Implemented:

The shell supports the following builtins without using external binaries:

echo (with -n option)
cd
pwd
export
unset
env
exit
