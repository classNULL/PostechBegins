// Type definitions for Mozilla's localForage
// Project: https://github.com/mozilla/localforage
// Definitions by: david pichsenmeister <https://github.com/3x14159265>
// Definitions: https://github.com/borisyankov/DefinitelyTyped

declare module lf {
    interface ILocalForage<T> {
        clear(): void
        key(index: number): T
        length: number
        getItem(key: string, callback: ICallback<T>): void
        getItem(key: string): Promise<T>
        setItem(key: string, value: T, callback: ICallback<T>): void
        setItem(key: string, value: T): Promise<T>
        removeItem(key: string, callback: ICallback<T>): void
        removeItem(key: string): Promise<T>
    }

    interface ICallback<T> {
        (data: T): void
    }
}
declare var localforage: lf.ILocalForage<any>