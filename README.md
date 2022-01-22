<h1 align="center">
    philosophers
</h1>

<p align="center">
	<b><i>42 philosophers development repository.</i></b><br>
	I never thought philosophy would be so deadly
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/philosophers?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/philosophers?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/philosophers?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/philosophers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/philosophers?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> In this project, you will learn the basics of threading a process.You will see how to create threads and you will discover mutexes.

## 📑 Index

`@root`
* [**📁 includes:**](/includes/) A common folder.
* [**📁 srcs:**](/srcs/) A common folder.
	* [**📁 parsing:**](/srcs/parsing/) A common folder.
	* [**📁 philosophers:**](/srcs/philosophers/) A common folder.
	* [**📁 threads:**](/srcs/threads/) A common folder.
	* [**📁 utils:**](/srcs/utils/) A common folder.



`@/srcs/main.c`
* `int main(int argc, char **argv)` - A rly cool functions.
* `static int launch_eat_monitor_thread(t_app *app)` - A rly cool functions.
* `void init(t_philosopher *philosopher)` - A rly cool functions.
* `static void check(t_app *app, t_philosopher *philosopher)` - A rly cool functions.

`@/srcs/utils/utils.c`
* `int should_be_dead(t_philosopher *philosopher)` - A rly cool functions.
* `long long get_time(void)` - A rly cool functions.

`@/srcs/utils/parsing_utils.c`
* `int	ft_atoi(char *str)` - A rly cool functions.
* `int	is_number(char *a)` - A rly cool functions.

`@/srcs/threads/thread_validator.c`
* `int	validate_thread(int code)` - A rly cool functions.

`@/srcs/philosophers/state.c`
* `int	is_state(t_philosopher *philosopher, t_philosopher_state state)` - A rly cool functions.
* `void	set_state(t_philosopher *philosopher, t_philosopher_state state)` - A rly cool functions.

`@/srcs/philosophers/new.c`
* `void	create_philosophers(t_app *app)` - A rly cool functions.
* `void	start(t_app *app)` - A rly cool functions.
* `static void	create_forks(t_app *app)` - A rly cool functions.
* `static t_philosopher	*create_philosopher(t_app *app, int index)` - A rly cool functions.

`@/srcs/philosophers/live.c`
* `void	*live(void *arg)` - A rly cool functions.
* `static int launch_monitor_thread(t_philosopher *philosopher)` - A rly cool functions.
* `static void *monitor(void *arg)` - A rly cool functions.
* `void *eat_monitor(void *arg)` - A rly cool functions.

`@/srcs/philosophers/fork.c`
* `void clear_forks(t_philosopher *philosopher)` - A rly cool functions.
* `void take_forks(t_philosopher *philosopher)` - A rly cool functions.

`@/srcs/philosophers/eat.c`
* `void eat(t_philosopher *philosopher)` - A rly cool functions.

`@/srcs/philosophers/clear.c`
* `void	clear_philosophers(t_app *app)` - A rly cool functions.

`@/srcs/parsing/parse.c`
* `void	parse_settings(t_settings *settings, int argc, char **argv)` - A rly cool functions.
* `static void	set_setting(t_settings *settings, int key, int value)` - A rly cool functions.
* `int	validate_settings(t_settings settings)` - A rly cool functions.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

#### 1. Installation

In order to install the philosophers, you need to clone it:

```bash
git clone https://github.com/RochBlondiaux/philosophers.git && cd philosophers
```

Then, compile it with:

```bash
make
```

#### 2. Usage

It's really simple, you just have to execute this command:

```bash
./philo <count> <die> <eat> <sleep> [times_each_must_eat]
```
