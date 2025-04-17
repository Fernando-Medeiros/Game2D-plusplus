namespace GameEngine.Adapters;

public struct SoundAdapter()
{
    private Sound _sound;

    public SoundAdapter(object drawable) : this()
    {
        _sound = (Sound?)drawable ?? throw new NullReferenceException();
    }

    public readonly object GetDrawable() => _sound;

#if RAYLIB
    public readonly void Play() => Raylib.PlaySound(_sound);
    public readonly float GetVolume() => Raylib.GetMasterVolume();
    public readonly void SetVolume(float volume) => Raylib.SetSoundVolume(_sound, volume);
#else
    public readonly void Play() => _sound.Play();
    public readonly float GetVolume() => _sound.Volume;
    public readonly void SetVolume(float volume) => _sound.Volume = volume;
#endif

    public void Dispose()
    {
#if RAYLIB
        Raylib.UnloadSound(_sound);
#else
        _sound.Dispose();
        _sound = null;
#endif
    }

    public static implicit operator Sound(SoundAdapter adapter) => (Sound)adapter.GetDrawable();

    public static implicit operator SoundAdapter(Sound drawable) => new(drawable);
}
