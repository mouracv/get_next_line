<h1 align="center">
	Get_next_line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

## 💡 About the project

**Get_next_line** is a custom implementation of the `getline` function in C. It reads and returns lines from a file descriptor, one at a time — handling variable-length lines efficiently. 

This is especially useful when working with large files or streaming data.

## 🎓 Learning Objective

The purpose of this project is to deepen understanding of:

- How file descriptors work in Unix-based systems.
- The process of opening, reading from, and closing files in C.
- Memory management and dynamic allocation.
- Buffering strategies and handling edge cases.

Understanding these fundamentals is essential for any future developer, especially when dealing with low-level data handling and file I/O.

## 📄 Function Prototype

```c
char *get_next_line(int fd);
```
**fd**: File descriptor to read from.

**Returns**: A pointer to the next line read, or NULL if the end of the file is reached or an error occurs.

**Note**: The returned string should be freed after use.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Installation and Testing

1. **Clone the repository**

    Start by cloning this repository to your local machine:
    ```sh
    git clone https://github.com/mouracv/get_next_line ; cd get_next_line
    ```

2. **Create a test file**
    
    Create a main.c file with the following example code to test the function
    ```c
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main()
    {
        int fd = open("main.c", O_RDONLY);
        char *line;
        
        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return (0);
    }
    ```
    This example reads its own source file line by line and prints the result to the terminal.

3. **Compile the program**

    Compile using the mandatory version:
    ```sh
    cc -o main main.c get_next_line.c get_next_line_utils.c
    ```
    > It's also possible to define the buffersize by adding `-D BUFFER_SIZE=42`

4. **Run the program** 

    ```sh
    ./main
    ```

**🔁 Bonus Version**

The bonus version supports reading from **multiple file descriptors simultaneously**, allowing you to manage several files at once without losing the reading state of each.

---

**🧪 Example Usage**

Replace the content of your `main.c` with the following code:
```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1;
    char *line2;

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    printf("From file1: %s", line1);
    printf("From file2: %s", line2);

    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    return (0);
}
```
> Make sure you create `file1.txt` and `file2.txt` with some example text inside.

To compile the bonus version, which supports reading from multiple file descriptors at once:
```sh
cc -o main main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
> This version enables simultaneous reading from different file descriptors without interference between them.

<br>

## 👨‍💻 Author
- [GitHub](https://github.com/mouracv)
- [Linkedin](https://www.linkedin.com/in/alexsandro-moreira-2b438a347/)
