interface Screen {
    lock(orientation: string): Promise<void>;
    unlock(): void;
    lockOrientation(orientation: string): boolean;
    mozLockOrientation(orientation: string): boolean;
}
if (!Screen.prototype.lock)
    Screen.prototype.lock = (orientation: string) => {
        return new Promise<void>((resolve, reject) => {
            var lockOrientation = screen.lockOrientation || screen.mozLockOrientation || screen.msLockOrientation;
            if (lockOrientation && lockOrientation.call(screen, orientation))
                resolve();
            else
                reject(new Error("Screen couldn't be locked."));
        });
    };