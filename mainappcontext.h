#ifndef MAINAPPCONTEXT_H
#define MAINAPPCONTEXT_H

#include <string>
#include <QString>
#include <QStringList>

class MainAppContext
{
public:
	static MainAppContext parse(int argc, char *argv[]);

	int getIntArg(const QString &arg) const
	{
		int ind = extraargs.indexOf(arg);
		if (ind < 0)
			return 0ll;
		return extraargs[ind + 1].toLongLong();
	}
	QString getStringArg(const QString &arg) const
	{
		int ind = extraargs.indexOf(arg);
		if (ind < 0)
			return QString();
		return extraargs[ind + 1].trimmed();
	}
	bool containsArg(const QString &arg) const
	{
		return extraargs.contains(arg);
	}
	QString getCurrentBinName() const
	{
		return binname;
	}
	void addbin(const std::string &desc, std::function<int(MainAppContext&)> f)
	{
		binaries[desc] = f;
	};
	int runBinary(const std::string &binname);

	int argc;
	char **argv;
	QString binname;
	QStringList extraargs;
	std::unordered_map<std::string, std::function<int(MainAppContext&)>> binaries;

protected:
	MainAppContext();
};

#endif // MAINAPPCONTEXT_H
