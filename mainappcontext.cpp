#include "mainappcontext.h"

MainAppContext MainAppContext::parse(int argc, char *argv[])
{
	MainAppContext ctx;
	ctx.argc = argc;
	ctx.argv = argv;
	ctx.binname = QString::fromUtf8(argv[0]).split('/').last();
	for (int i = 1; i < argc; i++)
		ctx.extraargs << QString::fromUtf8(argv[i]);
	return ctx;
}

int MainAppContext::runBinary(const std::string &binname)
{
	if (binaries.count(binname))
		return binaries[binname](*this);
	qDebug("unknown application: %s", binname.data());
	return -ENOENT;
}

MainAppContext::MainAppContext()
{

}
