// SPDX-License-Identifier: GPL-2.0

#include <linux/ipc_namespace.h>

struct ipc_namespace* get_init_ipc_ns_ptr(void);

#include <linux/version.h>
#include <linux/cred.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,15,2))
int security_binder_set_context_mgr(const struct cred *mgr);
int security_binder_transaction(const struct cred *from, const struct cred *to);
int security_binder_transfer_binder(const struct cred *from, const struct cred *to);
int security_binder_transfer_file(const struct cred *from, const struct cred *to, const struct file *file);
#else
int security_binder_set_context_mgr(struct task_struct *mgr);
int security_binder_transaction(struct task_struct *from, struct task_struct *to);
int security_binder_transfer_binder(struct task_struct *from, struct task_struct *to);
int security_binder_transfer_file(struct task_struct *from, struct task_struct *to, struct file *file);
#endif
