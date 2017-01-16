/**
* LICENSE PLACEHOLDER
*
* @file streaming_dload_window.h
* @class StreamingDloadWindow
* @package OpenPST
* @brief Streaming DLOAD GUI interface class definitions
*
* @author Gassan Idriss <ghassani@gmail.com>
*/

#pragma once

#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include "ui_streaming_dload_window.h"
#include "qualcomm/streaming_dload.h"
#include "qualcomm/streaming_dload_serial.h"
#include "task/streaming_dload_read_task.h"
#include "task/streaming_dload_stream_write_task.h"
#include "task/task_runner.h"
#include "about_dialog.h"


namespace Ui {
	class StreamingDloadWindow;
}

using OpenPST::QC::StreamingDloadSerialError;
using OpenPST::Serial::SerialError;

namespace OpenPST{
	namespace GUI {
		class StreamingDloadWindow : public QMainWindow
		{

            Q_OBJECT

            private:
                Ui::StreamingDloadWindow *ui;
                TaskRunner taskRunner;
                volatile bool taskShouldCancel = false;
				StreamingDloadSerial port;
                serial::PortInfo currentPort;
                int taskCount = 0;
                AboutDialog aboutDialog;
			public:
				explicit StreamingDloadWindow(QWidget *parent = 0);
				~StreamingDloadWindow();


			public slots:

				/**
				 * @brief updatePortList
				 */
				void updatePortList();

				/**
				 * @brief connectToPort
				 */
				void connectToPort();

				/**
				 * @brief disconnectPort
				 */
				void disconnectPort();

				/**
				 * @brief sendHello
				 */
				void sendHello();

				/**
				* @brief sendUnlock
				*/
				void sendUnlock();

				/**
				* @brief setSecurityMode
				*/
				void setSecurityMode();

				/**
				* @brief sendNop
				*/
				void sendNop();

				/**
				* @brief sendReset
				*/
				void sendReset();

				/**
				* @brief sendPowerDown
				*/
				void sendPowerDown();

				/**
				* @brief openMode
				*/
				void openMode();

				/**
				* @brief closeMode
				*/
				void closeMode();

				/**
				* @brief openMultiMode
				*/
				void openMultiMode();

				/**
				* @brief readEccState
				*/
				void readEccState();

				/**
				* @brief setEccState
				*/
				void setEccState();

				/**
				* @brief read - Read address and size
				*/
				void read();

				/**
				* @brief streamWrite - Stream write file starting at spcified address
				*/
				void streamWrite();

				/**
				* @brief eraseFlash
				*/
				void eraseFlash();

				/**
				* @brief browseForPartitionTable
				*/
				void browseForParitionTable();

				/**
				* @brief writePartitionTable
				*/
				void writePartitionTable();

				/**
				* @brief browseForWriteFile
				*/
				void browseForWriteFile();
            

                void showAboutDialog();

                void cancelCurrentTask();
                void cancelAllTasks();
                void onTaskStarted();
                void onTaskComplete();
                void onTaskAborted();
                void onTaskError(QString msg);
                void onTaskLog(QString msg);

            protected:
                void closeEvent(QCloseEvent *event);
                void addTask(Task* task);

			};
	}
}