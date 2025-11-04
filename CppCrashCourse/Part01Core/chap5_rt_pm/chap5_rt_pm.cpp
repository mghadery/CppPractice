#include <cstdio>

namespace chap5_rt_pm {
	struct Logger {
		virtual void log(const char *str) const = 0;  //pure virtual
		virtual ~Logger() = default;

	};

	struct Logger1 :Logger {
		void log(const char* str) const override{
			printf("logger 1 log function: %s\r\n", str);
		}

		~Logger1() {
			printf("logger1 destructor\r\n");
		}
	};

	struct Logger2 :Logger {
		void log(const char* str) const override{
			printf("logger 2 log function: %s\r\n", str);
		}

		~Logger2() {
			printf("logger2 destructor\r\n");
		}
	};

	struct Process {
		Process(Logger& lg) : logger(lg){

		}

		void act() {
			logger.log("Action");
		}

	private:
		Logger& logger;
	};

	void run()
	{
		Logger1 logger1;
		Logger2 logger2;

		Process process1{ logger1 };
		process1.act();

		Process process2{ logger2 };
		process2.act();
	}
}

