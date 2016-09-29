/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_stream_write_task.h
* @class StreamingDloadStreamWriteWorker
* @package OpenPST
* @brief Handles background processing of writing data to flash using streaming write 
*
* @author Gassan Idriss <ghassani@gmail.com>
*/
#ifndef _GUI_TASK_STREAMING_DLOAD_WRITE_TASK_H
#define _GUI_TASK_STREAMING_DLOAD_WRITE_TASK_H

#include <QThread>
#include "qc/streaming_dload_serial.h"
#include "qc/streaming_dload.h"
#include "gui/task/task.h"

using OpenPST::QC::StreamingDloadSerial;

namespace OpenPST {
	namespace GUI {
		class StreamingDloadStreamWriteTask : public Task
		{
		    public:
                StreamingDloadStreamWriteTask(uint32_t address, std::string writeFilePath, bool unframed, StreamingDloadSerial& port);
                ~StreamingDloadStreamWriteTask();
                void run();

		    protected:
			    StreamingDloadSerial&  port;
                uint32_t address;
                std::string writeFilePath;
                bool unframed;
		};
	}
}

#endif // _GUI_TASK_STREAMING_DLOAD_WRITE_TASK_H