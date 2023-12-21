import cmd

class MyCmdInterpreter(cmd.Cmd):
    prompt = "MyCmd> "

    def do_hello(self, line):
        """This is the 'hello' command description."""
        print("Hello, " + line)

    def do_quit(self, line):
        """Exit the interpreter."""
        return True

if __name__ == "__main__":
    interpreter = MyCmdInterpreter()
    interpreter.cmdloop()
