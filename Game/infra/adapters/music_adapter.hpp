namespace GameEngine.Adapters;

public sealed class MusicAdapter(object drawable)
{
    private Music _binding = (Music?)drawable ?? throw new NullReferenceException();

    public object GetDrawable() => _binding;

#if RAYLIB
    public void SetLoop(bool loop) => _binding.Looping = loop;
    public void SetVolume(float volume) => Raylib.SetMusicVolume(_binding, volume);
    public float GetVolume() => Raylib.GetMasterVolume();
    public void Play() => Raylib.PlayMusicStream(_binding);
    public void Stop() => Raylib.StopMusicStream(_binding);
    public void Update() => Raylib.UpdateMusicStream(_binding);
#else
    public readonly void SetLoop(bool loop) => _binding.Loop = loop;
    public readonly void SetVolume(float volume) => _binding.Volume = volume;
    public readonly float GetVolume() => _binding.Volume;
    public readonly void Play() => _binding.Play();
    public readonly void Stop() => _binding.Stop();
#endif

    public void Dispose()
    {
#if RAYLIB
        Stop();
        Raylib.UnloadMusicStream(_binding);
#else
        _binding.Dispose();
        _binding = null;
#endif
    }

    public static implicit operator Music(MusicAdapter adapter) => (Music)adapter.GetDrawable();

    public static implicit operator MusicAdapter(Music drawable) => new(drawable);
}
