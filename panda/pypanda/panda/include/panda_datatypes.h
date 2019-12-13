
// NOTE: panda_datatypes.h is auto generated by the script create_panda_datatypes.py
// Please do not tinker with it!  Instead, fix the script that generates it

#define PYPANDA 1



// -----------------------------------
// Pull number 1 from panda/include/panda/panda_callback_list.h


// Just the enum defining callback numbering
// and prototypes for all those callbacks.

// NOTE: Pls read README before editing!

#define MAX_PANDA_PLUGINS 16
#define MAX_PANDA_PLUGIN_ARGS 32

typedef enum panda_cb_type {
    PANDA_CB_BEFORE_BLOCK_TRANSLATE,    // Before translating each basic block
    PANDA_CB_AFTER_BLOCK_TRANSLATE,     // After translating each basic block
    PANDA_CB_BEFORE_BLOCK_EXEC_INVALIDATE_OPT, // Before executing each basic
                                               // block (with option to
                                               // invalidate, may trigger
                                               // retranslation)
    PANDA_CB_BEFORE_BLOCK_EXEC,     // Before executing each basic block
    PANDA_CB_AFTER_BLOCK_EXEC,      // After executing each basic block
    PANDA_CB_INSN_TRANSLATE,        // Before an insn is translated
    PANDA_CB_INSN_EXEC,             // Before an insn is executed
    PANDA_CB_AFTER_INSN_TRANSLATE,  // After an insn is translated
    PANDA_CB_AFTER_INSN_EXEC,       // After an insn is executed

    PANDA_CB_VIRT_MEM_BEFORE_READ,  // Before read of virtual memory
    PANDA_CB_VIRT_MEM_BEFORE_WRITE, // Before write of virtual memory
    PANDA_CB_PHYS_MEM_BEFORE_READ,  // Before read of physical memory
    PANDA_CB_PHYS_MEM_BEFORE_WRITE, // Before write of physical memory

    PANDA_CB_VIRT_MEM_AFTER_READ,   // After read of virtual memory
    PANDA_CB_VIRT_MEM_AFTER_WRITE,  // After write of virtual memory
    PANDA_CB_PHYS_MEM_AFTER_READ,   // After read of physical memory
    PANDA_CB_PHYS_MEM_AFTER_WRITE,  // After write of physical memory

    PANDA_CB_MMIO_AFTER_READ,       // After each MMIO read
    PANDA_CB_MMIO_AFTER_WRITE,      // After each MMIO write

    PANDA_CB_HD_READ,               // Each HDD read
    PANDA_CB_HD_WRITE,              // Each HDD write
    PANDA_CB_GUEST_HYPERCALL,       // Hypercall from the guest (e.g. CPUID)
    PANDA_CB_MONITOR,               // Monitor callback
    PANDA_CB_CPU_RESTORE_STATE,     // In cpu_restore_state() (fault/exception)
    PANDA_CB_BEFORE_REPLAY_LOADVM,  // at start of replay, before loadvm
    PANDA_CB_ASID_CHANGED,          // When CPU asid (address space identifier) changes
    PANDA_CB_REPLAY_HD_TRANSFER,    // In replay, hd transfer
    PANDA_CB_REPLAY_NET_TRANSFER,   // In replay, transfers within network card
                                    // (currently only E1000)
    PANDA_CB_REPLAY_SERIAL_RECEIVE, // In replay, right after data is pushed
                                    // into the serial RX FIFO
    PANDA_CB_REPLAY_SERIAL_READ,    // In replay, right after a value is read from
                                    // the serial RX FIFO.
    PANDA_CB_REPLAY_SERIAL_SEND,    // In replay, right after data is popped from
                                    // the serial TX FIFO
    PANDA_CB_REPLAY_SERIAL_WRITE,   // In replay, right after data is pushed into
                                    // the serial TX FIFO.
    PANDA_CB_REPLAY_BEFORE_DMA,     // In replay, just before RAM case of
                                    // cpu_physical_mem_rw
    PANDA_CB_REPLAY_AFTER_DMA,      // In replay, just after RAM case of
                                    // cpu_physical_mem_rw
    PANDA_CB_REPLAY_HANDLE_PACKET,  // In replay, packet in / out
    PANDA_CB_AFTER_CPU_EXEC_ENTER,  // Just after cpu_exec_enter is called
    PANDA_CB_BEFORE_CPU_EXEC_EXIT,  // Just before cpu_exec_exit is called

    PANDA_CB_AFTER_MACHINE_INIT,    // Right after the machine is initialized,
                                    // before any code runs
    PANDA_CB_TOP_LOOP,              // At top of loop that manages emulation
    PANDA_CB_DURING_MACHINE_INIT,   // At the start of machine initialization

    PANDA_CB_MAIN_LOOP_WAIT,        // Called after main_loop in main_loop.c runs
    PANDA_CB_PRE_SHUTDOWN,          // Just before shutting down

    // Unassigned I/O
    PANDA_CB_UNASSIGNED_IO_READ,
    PANDA_CB_UNASSIGNED_IO_WRITE,

    PANDA_CB_BEFORE_HANDLE_EXCEPTION, // Allows you to monitor, modify,
                                      // or squash exceptions

    PANDA_CB_LAST
} panda_cb_type;

// Union of all possible callback function types
typedef union panda_cb {
    /* Callback ID: PANDA_CB_BEFORE_BLOCK_EXEC_INVALIDATE_OPT

       before_block_exec_invalidate_opt: called before execution of every basic
       block, with the option to invalidate the TB

       Arguments:
        CPUState *env: the current CPU state
        TranslationBlock *tb: the TB we are about to execute

       Return value:
        true if we should invalidate the current translation block
        and retranslate, false otherwise
    */
    bool (*before_block_exec_invalidate_opt)(CPUState *env, TranslationBlock *tb);

    /* Callback ID: PANDA_CB_BEFORE_BLOCK_EXEC

       before_block_exec: called before execution of every basic block

       Arguments:
        CPUState *env: the current CPU state
        TranslationBlock *tb: the TB we are about to execute

       Return value:
        unused
    */
    int (*before_block_exec)(CPUState *env, TranslationBlock *tb);

    /* Callback ID: PANDA_CB_AFTER_BLOCK_EXEC

       after_block_exec: called after execution of every basic block, although
       if exitCode > TB_EXIT_IDX1, then the block exited early

       Arguments:
        CPUState *env: the current CPU state
        TranslationBlock *tb: the TB we just executed
        uint8_t exitCode:  why the block execution exited

       Return value:
        unused
    */
    int (*after_block_exec)(CPUState *env, TranslationBlock *tb, uint8_t exitCode);

    /* Callback ID: PANDA_CB_BEFORE_BLOCK_TRANSLATE

       before_block_translate: called before translation of each basic block

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC we are about to translate

       Return value:
        unused
    */
    int (*before_block_translate)(CPUState *env, target_ulong pc);

    /* Callback ID: PANDA_CB_AFTER_BLOCK_TRANSLATE

       after_block_translate: called after the translation of each basic block

       Arguments:
        CPUState *env: the current CPU state
        TranslationBlock *tb: the TB we just translated

       Return value:
        unused

       Notes:
        This is a good place to perform extra passes over the generated
        code (particularly by manipulating the LLVM code)
        FIXME: How would this actually work? By this point the out ASM
            has already been generated. Modify the IR and then regenerate?
    */
    int (*after_block_translate)(CPUState *env, TranslationBlock *tb);

    /* Callback ID: PANDA_CB_AFTER_CPU_EXEC_ENTER

       after_cpu_exec_enter: called after cpu_exec calls cpu_exec_enter function

       Arguments:
        CPUState *env: the current CPU state

       Return value:
        unused
    */
    int (*after_cpu_exec_enter)(CPUState *env);

    /* Callback ID: PANDA_CB_BEFORE_CPU_EXEC_EXIT

       before_cpu_exec_exit: called before cpu_exec calls cpu_exec_exit function

       Arguments:
        CPUState *env: the current CPU state
        bool ranBlock: true if ran a block since previous cpu_exec_enter

       Return value:
        unused
    */
    int (*before_cpu_exec_exit)(CPUState *env, bool ranBlock);

    /* Callback ID: PANDA_CB_INSN_TRANSLATE

       insn_translate: called before the translation of each instruction

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC we are about to translate

       Return value:
        true if PANDA should insert instrumentation into the generated code,
        false otherwise

       Notes:
        This allows a plugin writer to instrument only a small number of
        instructions, avoiding the performance hit of instrumenting everything.
        If you do want to instrument every single instruction, just return
        true. See the documentation for PANDA_CB_INSN_EXEC for more detail.
    */
    bool (*insn_translate)(CPUState *env, target_ulong pc);

    /* Callback ID: PANDA_CB_INSN_EXEC

       insn_exec: called before execution of any instruction identified
        by the PANDA_CB_INSN_TRANSLATE callback

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC we are about to execute

       Return value:
        unused

       Notes:
        This instrumentation is implemented by generating a call to a
        helper function just before the instruction itself is generated.
        This is fairly expensive, which is why it's only enabled via
        the PANDA_CB_INSN_TRANSLATE callback.
    */
    int (*insn_exec)(CPUState *env, target_ulong pc);

    /* Callback ID: PANDA_CB_AFTER_INSN_TRANSLATE

       after_insn_translate: called after the translation of each instruction

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the next guest PC we've translated

       Return value:
        true if PANDA should insert instrumentation into the generated code,
        false otherwise

       Notes:
        See `insn_translate`, callbacks are registered via PANDA_CB_AFTER_INSN_EXEC
    */
    bool (*after_insn_translate)(CPUState *env, target_ulong pc);

    /* Callback ID: PANDA_CB_AFTER_INSN_EXEC

       after_insn_exec: called after execution of an instruction identified
        by the PANDA_CB_AFTER_INSN_TRANSLATE callback

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the next guest PC already executed

       Return value:
        unused

       Notes:
        See `insn_exec`. Enabled via the PANDA_CB_AFTER_INSN_TRANSLATE callback.
    */
    int (*after_insn_exec)(CPUState *env, target_ulong pc);

    /* Callback ID: PANDA_CB_VIRT_MEM_BEFORE_READ

       virt_mem_before_read: called before memory is read

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the read
        target_ulong addr: the (virtual) address being read
        target_ulong size: the size of the read

       Return value:
        unused
    */
    int (*virt_mem_before_read)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size);

    /* Callback ID: PANDA_CB_VIRT_MEM_BEFORE_WRITE

       virt_mem_before_write: called before memory is written
       [exists]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the write
        target_ulong addr: the (virtual) address being written
        target_ulong size: the size of the write
        void *buf: pointer to the data that is to be written

       Return value:
        unused
    */
    int (*virt_mem_before_write)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_PHYS_MEM_BEFORE_READ

       phys_mem_before_read: called after memory is read
       [new]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the read
        target_ulong addr: the (physical) address being read
        target_ulong size: the size of the read

       Return value:
        unused
    */
    int (*phys_mem_before_read)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size);

    /* Callback ID: PANDA_CB_PHYS_MEM_BEFORE_WRITE

       phys_mem_write: called before memory is written
       [exists]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the write
        target_ulong addr: the (physical) address being written
        target_ulong size: the size of the write
        void *buf: pointer to the data that is to be written

       Return value:
        unused
    */
    int (*phys_mem_before_write)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_VIRT_MEM_AFTER_READ

       virt_mem_after_read: called after memory is read
       [exists]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the read
        target_ulong addr: the (virtual) address being read
        target_ulong size: the size of the read
        void *buf: pointer to data just read

       Return value:
        unused
    */
    int (*virt_mem_after_read)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_VIRT_MEM_AFTER_WRITE

       virt_mem_after_write: called after memory is written
       [new]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the write
        target_ulong addr: the (virtual) address being written
        target_ulong size: the size of the write
        void *buf: pointer to the data that was written

       Return value:
        unused
    */
    int (*virt_mem_after_write)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_PHYS_MEM_AFTER_READ

       phys_mem_after_read: called after memory is read
       [exists]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the read
        target_ulong addr: the (physical) address being read
        target_ulong size: the size of the read
        void *buf: pointer to data just read

       Return value:
        unused
    */

    int (*phys_mem_after_read)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_PHYS_MEM_AFTER_WRITE

       phys_mem_write: called after memory is written
       [new]

       Arguments:
        CPUState *env: the current CPU state
        target_ulong pc: the guest PC doing the write
        target_ulong addr: the (physical) address being written
        target_ulong size: the size of the write
        void *buf: pointer to the data that was written

       Return value:
        unused
    */

    int (*phys_mem_after_write)(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void *buf);

    /* Callback ID: PANDA_CB_MMIO_AFTER_READ

       mmio_after_read: called after MMIO memory is read

       Arguments:
        CPUState *env: the current CPU state
        target_ulong addr: the (physical) address being read from
        target_ulong size: the size of the read
        uin64_t val: the value being read

       Return value:
        unused
    */
    int (*mmio_after_read)(CPUState *env, target_ulong addr, int size, uint64_t val);

    /* Callback ID: PANDA_CB_MMIO_AFTER_WRITE

       mmio_after_write: called after MMIO memory is written to

       Arguments:
        CPUState *env: the current CPU state
        target_ulong addr: the (physical) address being written to
        target_ulong size: the size of the write
        uin64_t val: the value being written

       Return value:
        unused
    */
    int (*mmio_after_write)(CPUState *env, target_ulong addr, int size, uint64_t val);

    /* Callback ID: PANDA_CB_HD_READ
       hd_read : called when there is a hard drive read

       Note: this was added to panda_cb_type enum but no callback prototype inserted
       Here is a stub.  I'm not sure what the args should be.
       Arguments
       CPUState *env
    */

    void (*hd_read)(CPUState *env);

    /* Callback ID: PANDA_CB_HD_WRITE
       hd_write : called when there is a hard drive write

       Note: this was added to panda_cb_type enum but no callback prototype inserted
       Here is a stub.  I'm not sure what the args should be.
       Arguments
       CPUState *env
    */

    void (*hd_write)(CPUState *env);

    /* Callback ID: PANDA_CB_GUEST_HYPERCALL
       guest_hypercall: called when a program inside the guest makes a
        hypercall to pass information from inside the guest to a plugin
       Arguments:
        CPUState *env: the current CPU state
       Return value:
        unused
       Notes:
        On x86, this is called whenever CPUID is executed. Plugins then
        check for magic values in the registers to determine if it really
        is a guest hypercall. Parameters can be passed in other registers.
        S2E accomplishes this by using a (currently) undefined opcode. We
        have instead opted to use an existing instruction to make development
        easier (we can use inline asm rather than defining the raw bytes).
        AMD's SVM and Intel's VT define hypercalls, but they are privileged
        instructinos, meaning the guest must be in ring 0 to execute them.
    */
    int (*guest_hypercall)(CPUState *env);

    /* Callback ID: PANDA_CB_MONITOR
       monitor: called when someone uses the plugin_cmd monitor command
       Arguments:
        Monitor *mon: a pointer to the Monitor
        const char *cmd: the command string passed to plugin_cmd
       Return value:
        unused
       Notes:
        The command is passed as a single string. No parsing is performed
        on the string before it is passed to the plugin, so each plugin
        must parse the string as it deems appropriate (e.g. by using strtok
        and getopt) to do more complex option processing.
        It is recommended that each plugin implementing this callback respond
        to the "help" message by listing the commands supported by the plugin.
        Note that every loaded plugin will have the opportunity to respond to
        each plugin_cmd; thus it is a good idea to ensure that your plugin's
        monitor commands are uniquely named, e.g. by using the plugin name
        as a prefix ("sample_do_foo" rather than "do_foo").
    */
    int (*monitor)(Monitor *mon, const char *cmd);

    /* Callback ID: PANDA_CB_CPU_RESTORE_STATE

       cpu_restore_state: called inside of cpu_restore_state(), when there is
        a CPU fault/exception

       Arguments:
        CPUState *env: the current CPU state
        TranslationBlock *tb: the current translation block

       Return value:
        unused
    */
    int (*cpu_restore_state)(CPUState *env, TranslationBlock *tb);

    /* Callback ID: PANDA_CB_BEFORE_REPLAY_LOADVM

       before_loadvm: called at start of replay, before loadvm is called.
        This allows us to hook devices' loadvm handlers.
        Remember to unregister the existing handler for the device first.
        See the example in the sample plugin.

        Arguments:

        Return value:
         unused
    */
    int (*before_replay_loadvm)(void);

    /* Callback ID: PANDA_CB_ASID_CHANGED

       asid_changed: Called when asid changes.

       Arguments:
        CPUState* env: pointer to CPUState
        target_ulong oldval: old asid value
        target_ulong newval: new asid value

       Return value:
        unused
    */
    int (*asid_changed)(CPUState *env, target_ulong oldval, target_ulong newval);

    /* Callback ID:     PANDA_CB_REPLAY_HD_TRANSFER,

       In replay only, some kind of data transfer involving hard drive.
       NB: We are neither before nor after, really.
       In replay the transfer doesn't really happen.
       We are *at* the point at which it happened, really.

       Arguments:
        CPUState* env: pointer to CPUState
        uint32_t type:        type of transfer  (Hd_transfer_type)
        uint64_t src_addr:    address for src
        uint64_t dest_addr:   address for dest
        uint32_t num_bytes:   size of transfer in bytes

       Return value:
        non-zero means DONT change asid
    */
    int (*replay_hd_transfer)(CPUState *env, uint32_t type, uint64_t src_addr, uint64_t dest_addr, uint32_t num_bytes);

    /* Callback ID:     PANDA_CB_REPLAY_NET_TRANSFER,

       In replay only, some kind of data transfer within the network card
       (currently, only the E1000 is supported).  NB: We are neither before nor
       after, really.  In replay the transfer doesn't really happen.  We are
       *at* the point at which it happened, really.

       Arguments:
        CPUState* env:        pointer to CPUState
        uint32_t type:        type of transfer  (Net_transfer_type)
        uint64_t src_addr:    address for src
        uint64_t dest_addr:   address for dest
        uint32_t num_bytes:   size of transfer in bytes

       Return value:
        unused
    */
		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_net_transfer)(CPUState *env, uint32_t type, uint64_t src_addr, uint64_t dest_addr, uint32_t num_bytes);

    /* Callback ID:     PANDA_CB_REPLAY_SERIAL_RECEIVE,

       In replay only, called when a byte is received on the serial port.

       Arguments:
        CPUState* env:        pointer to CPUState
        uint64_t fifo_addr:   address of the data within the fifo
        uint8_t value:        value received

       Return value:
        unused
    */

		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_serial_receive)(CPUState *env, uint64_t fifo_addr, uint8_t value);

    /* Callback ID:     PANDA_CB_REPLAY_SERIAL_READ,

       In replay only, called when a byte read from the serial RX FIFO

       Arguments:
        CPUState* env:        pointer to CPUState
        uint64_t fifo_addr:   address of the data within the fifo (source)
        uint32_t port_addr:   address of the IO port where data is being
                              read (destination)
        uint8_t value:        value read

       Return value:
        unused
    */

		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_serial_read)(CPUState *env, uint64_t fifo_addr, uint32_t port_addr, uint8_t value);

    /* Callback ID:     PANDA_CB_REPLAY_SERIAL_SEND,

       In replay only, called when a byte is sent on the serial port.

       Arguments:
        CPUState* env:        pointer to CPUState
        uint64_t fifo_addr:   address of the data within the fifo
        uint8_t value:        value received

       Return value:
        unused
    */
    int (*replay_serial_send)(CPUState *env, uint64_t fifo_addr, uint8_t value);

    /* Callback ID:     PANDA_CB_REPLAY_SERIAL_WRITE,

       In replay only, called when a byte written to the serial TX FIFO

       Arguments:
        CPUState* env:        pointer to CPUState
        uint64_t fifo_addr:   address of the data within the fifo (source)
        uint32_t port_addr:   address of the IO port where data is being
                              read (destination)
        uint8_t value:        value read

       Return value:
        unused
    */

		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_serial_write)(CPUState *env, uint64_t fifo_addr, uint32_t port_addr, uint8_t value);

    /* Callback ID:     PANDA_CB_REPLAY_BEFORE_DMA,

       In replay only, we are about to dma between qemu buffer and guest memory

       Arguments:
        CPUState* env:       pointer to CPUState
        uint32_t is_write:   type of transfer going on    (is_write == 1 means IO -> RAM else RAM -> IO)
        uint8_t* buf         the QEMU device's buffer in QEMU's virtual memory
        uint64_t paddr       "physical" address of guest RAM
        uint32_t num_bytes:  size of transfer
    */

		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_before_dma)(CPUState *env, uint32_t is_write, uint8_t* src_addr, uint64_t dest_addr, uint32_t num_bytes);

    /* Callback ID:     PANDA_CB_REPLAY_AFTER_DMA,

       In replay only, we are about to dma between qemu buffer and guest memory

       Arguments:
        CPUState* env:       pointer to CPUState
        uint32_t is_write:   type of transfer going on    (is_write == 1 means IO -> RAM else RAM -> IO)
        uint8_t* buf         the QEMU device's buffer in QEMU's virtual memory
        uint64_t paddr       "physical" address of guest RAM
        uint32_t num_bytes:  size of transfer
    */

		// XXX: This entire definition must remain on one line in order to support pypanda's create_data_types.py logic
    int (*replay_after_dma)(CPUState *env, uint32_t is_write, uint8_t* src_addr, uint64_t dest_addr, uint32_t num_bytes);

    /* Callback ID:   PANDA_CB_REPLAY_HANDLE_PACKET,

       In replay only, we have a packet (incoming / outgoing) in hand.

       Arguments:
        CPUState *env          pointer to CPUState
        uint8_t *buf           buffer containing packet data
        int size               num bytes in buffer
        uint8_t direction      XXX read or write.  not sure which is which.
        uint64_t old_buf_addr  XXX this is a mystery
    */
    int (*replay_handle_packet)(CPUState *env, uint8_t *buf, int size, uint8_t direction, uint64_t old_buf_addr);

    /* Callback ID:     PANDA_CB_AFTER_MACHINE_INIT

       after_machine_init: Called right after the machine has been
       initialized, but before any guest code runs.

       Arguments:
        void *cpu_env: pointer to CPUState

       Return value:
        unused

       Notes:
        This callback allows initialization of components that need access
       to the RAM, CPU object, etc. E.g. for the taint2 plugin, this is the
       appropriate place to call taint2_enable_taint().
    */
    void (*after_machine_init)(CPUState *env);

    /* Callback ID:     PANDA_CB_TOP_LOOP

       top_loop: Called at the top of the loop that manages emulation.

       Arguments:
        void *cpu_env: pointer to CPUState

       Return value:
        unused
     */
    void (*top_loop)(CPUState *env);
    /* Callback ID:     PANDA_CB_DURING_MACHINE_INIT

       during_machine_init: Called in the middle of machine initialization

       Arguments:
         MachineState *machine: pointer to the machine state

       Return value:
         None
     */

    void (*during_machine_init)(MachineState *machine);

    /* Callback ID:     PANDA_CB_MAIN_LOOP_WAIT

       main_loop_wait: Called in IO thread in place where monitor cmds are processed

       Arguments:
         None

       Return value:
         None
     */

    void (*main_loop_wait)(void);

    /* Callback ID:     PANDA_CB_PRE_SHUTDOWN

      pre_shutdown: Called just before qemu shuts down

       Arguments:
         None

       Return value:
         None
     */
    void (*pre_shutdown)(void);

    /* TODO: Document */
    void (*unassigned_io_read)(CPUState *env, target_ulong pc, hwaddr addr, uint32_t size, uint64_t *val);

    /* TODO: Document */
    void (*unassigned_io_write)(CPUState *env, target_ulong pc, hwaddr addr, uint32_t size, uint64_t *val);



    /* Callback ID:     PANDA_CB_BEFORE_HANDLE_EXCEPTION

       before_handle_exception: Called just before we are about to
       handle an exception.

       Note: only called for cpu->exception_index > 0

       Aguments:
         exception_index (the current exception number)

       Return value:
         a new exception_index.

       Note: There might be more than one callback for this location.
       First callback that returns an exception index that *differs*
       from the one passed as an arg wins. That is what we return as
       the new exception index, which will replace
       cpu->exception_index

     */

    int32_t (*before_handle_exception)(CPUState *cpu, int32_t exception_index);

    /* Dummy union member.

       This union only contains function pointers.
       Using the cbaddr member one can compare if two union instances
       point to the same callback function. In principle, any other
       member could be used instead.
       However, cbaddr provides neutral semantics for the comparisson.
    */
    void (* cbaddr)(void);
} panda_cb;



// -----------------------------------
// Pull number 2 from panda/include/panda/panda_plugin_mgmt.h

//  Manage plugins (load, enable, disable, etc).
//  and callbacks (regster, unregister, etc) .

// NOTE: Pls read README before editing!

// Doubly linked list that stores a callback, along with its owner
typedef struct _panda_cb_list panda_cb_list;
struct _panda_cb_list {
    panda_cb entry;
    void *owner;
    panda_cb_list *next;
    panda_cb_list *prev;
    bool enabled;
};

// Structure to store metadata about a plugin
typedef struct panda_plugin {
    char name[256];     // Currently basename(filename)
    void *plugin;       // Handle to the plugin (for use with dlsym())
} panda_plugin;

extern bool panda_plugins_to_unload[MAX_PANDA_PLUGINS];
extern bool panda_plugin_to_unload;

extern panda_cb_list *panda_cbs[PANDA_CB_LAST];

// plugin mgmt
bool panda_load_external_plugin(const char *filename, const char *plugin_name, 

                                void *plugin_uuid, void *init_fn_ptr);
bool panda_load_plugin(const char *filename, const char *plugin_name);
bool _panda_load_plugin(const char *filename, const char *plugin_name, bool library_mode);
char *panda_plugin_path(const char *name);
void panda_require(const char *plugin_name);
void panda_require_from_library(const char *plugin_name, char **plugin_args, uint32_t num_args);
void panda_do_unload_plugin(int index);
void panda_unload_plugin(void* plugin);
void panda_unload_plugin_idx(int idx);
void panda_unload_plugins(void);
void *panda_get_plugin_by_name(const char *name);
void panda_unload_plugin_by_name(const char* name);
void panda_enable_plugin(void *plugin);
void panda_disable_plugin(void *plugin);

// callback mgmt
void panda_register_callback(void *plugin, panda_cb_type type, panda_cb cb);
bool panda_is_callback_enabled(void *plugin, panda_cb_type type, panda_cb cb);
void panda_disable_callback(void *plugin, panda_cb_type type, panda_cb cb);
void panda_enable_callback(void *plugin, panda_cb_type type, panda_cb cb);
void panda_unregister_callbacks(void *plugin);
panda_cb_list* panda_cb_list_next(panda_cb_list* plist);



// -----------------------------------
// Pull number 3 from panda/include/panda/panda_args.h

// Fns and structs to do with panda arg parsing 

// NOTE: Pls read README before editing!

// Struct for holding a parsed key/value pair from
// a -panda-arg plugin:key=value style argument.
typedef struct panda_arg {
    char *argptr;   // For internal use only
    char *key;      // Pointer to the key string
    char *value;    // Pointer to the value string
} panda_arg;


typedef struct panda_arg_list {
    int nargs;
    panda_arg *list;
    char *plugin_name;
} panda_arg_list;



bool panda_add_arg(const char *plugin_name, const char *plugin_arg);

// Parse out arguments and return them to caller
panda_arg_list *panda_get_args(const char *plugin_name);

// Free a list of parsed arguments
void panda_free_args(panda_arg_list *args);

bool panda_parse_bool_req(panda_arg_list *args, const char *argname, const char *help);
bool panda_parse_bool_opt(panda_arg_list *args, const char *argname, const char *help);
bool panda_parse_bool(panda_arg_list *args, const char *argname);

target_ulong panda_parse_ulong_req(panda_arg_list *args, const char *argname, const char *help);
target_ulong panda_parse_ulong_opt(panda_arg_list *args, const char *argname, target_ulong defval, const char *help);
target_ulong panda_parse_ulong(panda_arg_list *args, const char *argname, target_ulong defval);

uint32_t panda_parse_uint32_req(panda_arg_list *args, const char *argname, const char *help);
uint32_t panda_parse_uint32_opt(panda_arg_list *args, const char *argname, uint32_t defval, const char *help);
uint32_t panda_parse_uint32(panda_arg_list *args, const char *argname, uint32_t defval);

uint64_t panda_parse_uint64_req(panda_arg_list *args, const char *argname, const char *help);
uint64_t panda_parse_uint64_opt(panda_arg_list *args, const char *argname, uint64_t defval, const char *help);
uint64_t panda_parse_uint64(panda_arg_list *args, const char *argname, uint64_t defval);

double panda_parse_double_req(panda_arg_list *args, const char *argname, const char *help);
double panda_parse_double_opt(panda_arg_list *args, const char *argname, double defval, const char *help);
double panda_parse_double(panda_arg_list *args, const char *argname, double defval);

const char *panda_parse_string_req(panda_arg_list *args, const char *argname, const char *help);
const char *panda_parse_string_opt(panda_arg_list *args, const char *argname, const char *defval, const char *help);
const char *panda_parse_string(panda_arg_list *args, const char *argname, const char *defval);

char** str_split(char* a_str, const char a_delim);
extern const gchar *panda_argv[MAX_PANDA_PLUGIN_ARGS];
extern int panda_argc;




// -----------------------------------
// Pull number 4 from panda/include/panda/panda_api.h

// Functions considered part of the panda api that come from
// panda_api.c. Also some from common.c. Note that, while common.c has
// a header (common.h) it is unsuitable for use with cffi since it is
// larded with inline fns. Note that the real panda API for pypanda is
// really in the pypanda/include/panda_datatypes.h file

// NOTE: Pls read README before editing!

/*
bool panda_flush_tb(void);
void panda_do_flush_tb(void);
void panda_enable_precise_pc(void);
void panda_disable_precise_pc(void);
void panda_enable_memcb(void);
void panda_disable_memcb(void);
void panda_enable_tb_chaining(void);
void panda_disable_tb_chaining(void);
void panda_enable_llvm(void);
void panda_disable_llvm(void);
void panda_enable_llvm_helpers(void);
void panda_disable_llvm_helpers(void);
void panda_memsavep(FILE *f);
//int panda_begin_replay(char *replay_name);
*/

// from panda_api.c
int panda_init(int argc, char **argv, char **envp);
int panda_run(void);
void panda_set_library_mode(bool);
void panda_stop(int code);
void panda_cont(void);
void panda_start_pandalog(const char *name);
int panda_revert(char *snapshot_name);
void panda_reset(void);
int panda_snap(char *snapshot_name);
int panda_finish(void);
bool panda_was_aborted(void);
target_ulong panda_virt_to_phys_external(CPUState *cpu, target_ulong virt_addr);

void panda_set_qemu_path(char* filepath);

int panda_init_plugin(char *plugin_name, char **plugin_args, uint32_t num_args);

void panda_register_callback_helper(void* plugin, panda_cb_type type, panda_cb* cb);
void panda_enable_callback_helper(void *plugin, panda_cb_type, panda_cb* cb);
void panda_disable_callback_helper(void *plugin, panda_cb_type, panda_cb* cb);

int rr_get_guest_instr_count_external(void);

int panda_virtual_memory_read_external(CPUState *env, target_ulong addr, char *buf, int len); // XXX: should we use hwaddr instead of target_ulong
int panda_virtual_memory_write_external(CPUState *env, target_ulong addr, char *buf, int len); // XXX: should we use hwaddr instead of target_ulong
int panda_physical_memory_read_external(hwaddr addr, uint8_t *buf, int len);
int panda_physical_memory_write_external(hwaddr addr, uint8_t *buf, int len);

target_ulong panda_current_sp_external(CPUState *cpu);
target_ulong panda_current_sp_masked_pagesize_external(CPUState *cpu, target_ulong pagesize);
bool panda_in_kernel_external(CPUState *cpu);

//void panda_monitor_run(char* buf, uint32_t len);
int panda_delvm(char *snapshot_name);


// Create a monitor for panda
void panda_init_monitor(void);

// Pass a message via the panda monitor. Create monitor if necessary'
// returns output string from monitor. Some commands may cause spinloops
char* panda_monitor_run(char* buf);

// Pass a message via the panda monitor. Create monitor if necessary'
// Does not return
void panda_monitor_run_async(char* buf);


// turns on taint
void panda_taint_enable(void) ;

// label this register
void panda_taint_label_reg(uint32_t reg_num, uint32_t label) ;

// returns true iff any byte in this register is tainted
bool panda_taint_check_reg(uint32_t reg_num, uint32_t size) ;


// Map a region of memory in the guest
//int panda_map_physical_mem(target_ulong addr, int len);



// -----------------------------------
// Pull number 5 from panda/include/panda/panda_os.h

// this stuff is defined / used in common.c

// NOTE: Pls read README before editing!

// this stuff is used by the new qemu cmd-line arg '-os os_name'
typedef enum OSFamilyEnum { OS_UNKNOWN, OS_WINDOWS, OS_LINUX } PandaOsFamily;

// these are set in panda/src/common.c via call to panda_set_os_name(os_name)
extern char *panda_os_name;           // the full name of the os, as provided by the user
extern char *panda_os_family;         // parsed os family
extern char *panda_os_variant;        // parsed os variant
extern uint32_t panda_os_bits;        // parsed os bits
extern PandaOsFamily panda_os_familyno; // numeric identifier for family


typedef target_ulong target_ptr_t;


// -----------------------------------
// Pull number 6 from panda/include/panda/panda_common.h


void panda_cleanup(void);
void panda_set_os_name(char *os_name);
void panda_before_find_fast(void);
void panda_disas(FILE *out, void *code, unsigned long size);
void panda_break_main_loop(void);

extern bool panda_break_cpu_loop_req;
extern bool panda_break_vl_loop_req;

/*
 * @brief Returns the guest address space identifier.
 */
target_ulong panda_current_asid(CPUState *env);

/**
 * @brief Returns the guest program counter.
 */
target_ulong panda_current_pc(CPUState *cpu);




