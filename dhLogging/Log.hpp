#pragma once
#include <stdio.h>

namespace dh {
	template <class T>
	class Log
	{
	private:
		FILE* logfile;
		const char* filename;
		bool binary;
		bool active;

	public:
		Log() {
			active = false;
			logfile = nullptr;
		}
		Log(const char* filename, bool binary = true) : binary(binary), filename(filename) {
			if (binary) fopen_s(&logfile, filename, "a+b");
			else fopen_s(&logfile, filename, "a+");
			active = true;
		}
		~Log() {
			pause();
		}

		template <class T>
		void log(const T& data, size_t elements = 1U) {
			if (!active) return;
			fwrite((void*)& data, sizeof(T), elements, logfile);
		}
		void pause(void) {
			if (!active) return;
			fclose(logfile);
			active = false;
		}
		void start(void) {
			if (active) return;
			if (binary) fopen_s(&logfile, filename, "a+b");
			else fopen_s(&logfile, filename, "a+");
			if (logfile == nullptr) return;
			active = true;
		}
		void setFilename(const char* filename, bool binary = true) {
			bool a = active;
			pause();
			this->binary = binary;
			this->filename = filename;
			if (a) start();
		}
		bool isActive(void) const { return active; }
	};
}