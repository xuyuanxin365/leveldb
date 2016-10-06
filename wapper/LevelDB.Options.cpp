#include "LevelDB.Options.h"

using namespace LevelDB;

Options::Options(void)
{
	this->CreateIfMissing = false;
	this->ErrorIfExists = false;
	this->ParanoidChecks = false;
	this->WriteBufferSize = 4 << 20;
	this->MaxOpenFiles = 1000;
	this->BlockSize = 4096;
	this->BlockRestartInterval = 16;
	this->MaxFileSize = 2 << 20;
	this->Compression = CompressionType::SnappyCompression;
	this->ReuseLogs = false;
	this->FilterPolicy = nullptr;
}

leveldb::Options Options::ToUnmanaged()
{
	leveldb::Options options;
	options.create_if_missing = CreateIfMissing;
	options.error_if_exists = ErrorIfExists;
	options.paranoid_checks = ParanoidChecks;
	options.write_buffer_size = WriteBufferSize;
	options.max_open_files = MaxOpenFiles;
	options.block_size = BlockSize;
	options.block_restart_interval = BlockRestartInterval;
	options.max_file_size = MaxFileSize;
	options.compression = (leveldb::CompressionType)(int)Compression;
	options.reuse_logs = ReuseLogs;
	options.filter_policy = FilterPolicy == nullptr ? nullptr : FilterPolicy->policy;
	return options;
}
