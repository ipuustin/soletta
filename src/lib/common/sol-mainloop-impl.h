/*
 * This file is part of the Soletta Project
 *
 * Copyright (C) 2015 Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

/* implement these functions for your own system so soletta will work */

#define SOL_LOG_DOMAIN &_sol_mainloop_log_domain
extern struct sol_log_domain _sol_mainloop_log_domain;
#include "sol-log-internal.h"
#include "sol-mainloop.h"


int sol_mainloop_impl_init(void);
void sol_mainloop_impl_run(void);
void sol_mainloop_impl_quit(void);
void sol_mainloop_impl_shutdown(void);

void *sol_mainloop_impl_timeout_add(uint32_t timeout_ms, bool (*cb)(void *data), const void *data);
bool sol_mainloop_impl_timeout_del(void *handle);

void *sol_mainloop_impl_idle_add(bool (*cb)(void *data), const void *data);
bool sol_mainloop_impl_idle_del(void *handle);

#ifdef SOL_MAINLOOP_FD_ENABLED
void *sol_mainloop_impl_fd_add(int fd, uint32_t flags, bool (*cb)(void *data, int fd, uint32_t active_flags), const void *data);
bool sol_mainloop_impl_fd_del(void *handle);
bool sol_mainloop_impl_fd_set_flags(void *handle, uint32_t flags);
uint32_t sol_mainloop_impl_fd_get_flags(const void *handle);
#endif

#ifdef SOL_MAINLOOP_FORK_WATCH_ENABLED
void *sol_mainloop_impl_child_watch_add(uint64_t pid, void (*cb)(void *data, uint64_t pid, int status), const void *data);
bool sol_mainloop_impl_child_watch_del(void *handle);
#endif

void *sol_mainloop_impl_source_add(const struct sol_mainloop_source_type *type, const void *data);
void sol_mainloop_impl_source_del(void *handle);
void *sol_mainloop_impl_source_get_data(const void *handle);
