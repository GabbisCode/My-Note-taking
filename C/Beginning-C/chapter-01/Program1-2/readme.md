# Editing Your First Program

The \” sequences that appears at the beginning and end of the text to be displayed is called an escape sequence, and there are several different escape sequences. Here, \” is a special way of including a double quote in the text to be output. This is necessary because double quotes (the straight kind, not curly quotes) are used to indicate where a character string begins and ends. The escape sequences cause a double quote to appear at the beginning and end
of the output. If you didn’t use the escape sequences, not only would the double quote characters not appear in the output, but the program would not compile.

# Dealing with Errors

To err is human, so there’s no need to be embarrassed about making mistakes.

Keep in mind that one error can result in error messages for subsequent statements that may actually be correct. This usually happens with statements that refer to something that is supposed to be defined by a statement containing an error. Of course, if a statement that defines something has an error, then what was supposed to be defined won’t be.

Don’t get put off by the number of errors reported. After you consider the messages carefully, the basic approach is to go back and edit your source code to fix at least the first
error, because that may have triggered other errors, and ignore the errors you can’t understand. Then have another go at compiling the source file. With luck, you’ll get fewer errors the next time around.
