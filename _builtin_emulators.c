#include "shell.h"
/**
 * _shexit - exits the shell
 *  @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *Return: exits with a given exit status
 *     (0) if info.argv[0] != "exit"
 */
int _shexit(info_t *info)
{
	int check_exit;

	if (info->argv[1])
	{
		check_exit = _erratoi(info->argv[1]);
		if (check_exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs_(info->argv[1]);
			_eputchar_('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /*TODO: what should this be?*/
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /*TODO: wgat should this be?*/
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "Can't cd to");
		_eputs_(info->argv[1]), _eputchar_('\n');
	}
	else
	{
		_set_env(info, "OLDPWD", _getenv(info, "PWD="));
		_set_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _help(info_t *info)
{
	char **args_array;

	args_array = info->argv;
	_puts("This is a simple shell that we created as part of the school project");
	if (0)
		_puts(*args_array);
	return (0);
}
