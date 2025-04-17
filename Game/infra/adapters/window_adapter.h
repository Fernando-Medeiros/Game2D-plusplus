namespace GameEngine.Adapters;

/// <summary>
/// Esta classe é responsável por adaptar a janela de renderização de uma biblioteca externa para a janela do jogo.
/// </summary>
public sealed class WindowAdapter : IWindow
{
    #region Event
    public event Action Closed = null;
    public event Action<RectAdapter> Resized = null;
    public event Action<KeyboardTransport> TextEntered = null;
    public event Action<KeyboardTransport> KeyPressed = null;
    public event Action<KeyboardTransport> KeyReleased = null;
    public event Action<MouseTransport> MouseMoved = null;
    public event Action<MouseTransport> MouseButtonReleased = null;
    public event Action<MouseTransport> MouseButtonPressed = null;
    public event Action<MouseTransport> MouseWheelScrolled = null;
    #endregion
    #region External Binding Event
    private void OnClosed(object? sender, EventArgs e) => Closed?.Invoke();
    private void OnResized(object? sender, SizeEventArgs e) => Resized?.Invoke(new RectAdapter(0, 0, (int)e.Width, (int)e.Height));
    private void OnTextEntered(object? sender, TextEventArgs e) => TextEntered?.Invoke(new KeyboardTransport(e.Unicode));
    private void OnKeyPressed(object? sender, KeyEventArgs e) => KeyPressed?.Invoke(new KeyboardTransport(e.Code.ToString()));
    private void OnKeyReleased(object? sender, KeyEventArgs e) => KeyReleased?.Invoke(new KeyboardTransport(e.Code.ToString()));
    private void OnMouseMoved(object? sender, MouseMoveEventArgs e) => MouseMoved?.Invoke(new MouseTransport(default, e.X, e.Y));
    private void OnMouseWheelScrolled(object? sender, MouseWheelScrollEventArgs e) => MouseWheelScrolled?.Invoke(new MouseTransport(Enum.Parse<EMouse>($"{e.Delta}"), e.X, e.Y));
    private void OnMouseButtonPressed(object? sender, MouseButtonEventArgs e) => MouseButtonPressed?.Invoke(new MouseTransport(Enum.Parse<EMouse>($"{e.Button}"), e.X, e.Y));
    private void OnMouseButtonReleased(object? sender, MouseButtonEventArgs e) => MouseButtonReleased?.Invoke(new MouseTransport(Enum.Parse<EMouse>($"{e.Button}"), e.X, e.Y));
    #endregion

    #region External Properties
    private RenderWindow _window;
    private ViewportAdapter _dynamicViewport;

    public uint _framerateLimit = 30;
    public string _title = string.Empty;
    #endregion

    #region Factory Pattern
    public static IWindow Emtpy => new WindowAdapter();

    public IWindow WithSize(VectorAdapter vector)
    {
        if (_window != null)
            _window.Size = vector;

        _dynamicViewport = new ViewportAdapter(vector / 2, vector);
        return this;
    }

    public IWindow WithTitle(string title)
    {
        _title = title;
        return this;
    }

    public IWindow WithFramerateLimit(int limit)
    {
        _framerateLimit = (uint)Math.Max(_framerateLimit, limit);
        return this;
    }

    public IWindow Build()
    {
        VectorAdapter size = _dynamicViewport.Size();

        if (_window == null)
        {
#if RAYLIB
            Raylib.InitAudioDevice();
#endif

            _window = new(new VideoMode((uint)size.X, (uint)size.Y), _title, Styles.Resize);
            _window.SetFramerateLimit(_framerateLimit);

            _window.Closed += OnClosed;
            _window.Resized += OnResized;
            _window.TextEntered += OnTextEntered;
            _window.KeyPressed += OnKeyPressed;
            _window.KeyReleased += OnKeyReleased;
            _window.MouseMoved += OnMouseMoved;
            _window.MouseWheelScrolled += OnMouseWheelScrolled;
            _window.MouseButtonPressed += OnMouseButtonPressed;
            _window.MouseButtonReleased += OnMouseButtonReleased;
        }
        return this;
    }
    #endregion

    #region Encapsulation
    public bool IsOpen() => _window.IsOpen;
    public VectorAdapter GetWindowSize() => _window.Size;
    public ViewportAdapter GetCurrentViewport() => _window.GetView();
    public ViewportAdapter GetDynamicViewport() => _dynamicViewport;
    public ViewportAdapter GetDefaultViewport() => _window.DefaultView;
    public VectorAdapter GetCoords(VectorAdapter vector, ViewportAdapter viewport) => _window.MapPixelToCoords(vector, viewport);
    public void Resize(VectorAdapter vector) => _window.Size = vector;
    public void SetViewport(ViewportAdapter viewport) => _window.SetView(viewport);
    #endregion

    #region Behavior Pattern
    public void Close() => _window.Close();

    public void Clear(EColor color) => _window.Clear(color.ToColor());

    public void Display() => _window.Display();

    public void DispatchEvents() => _window.DispatchEvents();

    public void RenderSync(DrawableAdapter adapter) => _window.Draw(adapter.GetDrawableToRender());
    #endregion

    void IDisposable.Dispose()
    {
#if RAYLIB
        Raylib.CloseAudioDevice();
#endif

        Closed = null;
        Resized = null;
        TextEntered = null;
        KeyPressed = null;
        KeyReleased = null;
        MouseMoved = null;
        MouseButtonReleased = null;
        MouseButtonPressed = null;
        MouseWheelScrolled = null;

        _window.Closed -= OnClosed;
        _window.Resized -= OnResized;
        _window.TextEntered -= OnTextEntered;
        _window.KeyPressed -= OnKeyPressed;
        _window.KeyReleased -= OnKeyReleased;
        _window.MouseMoved -= OnMouseMoved;
        _window.MouseWheelScrolled -= OnMouseWheelScrolled;
        _window.MouseButtonPressed -= OnMouseButtonPressed;
        _window.MouseButtonReleased -= OnMouseButtonReleased;

        _window.Dispose();
        _dynamicViewport.Dispose();

        _window = null;
        _dynamicViewport = null;

        GC.Collect(GC.GetGeneration(this), GCCollectionMode.Forced);
        GC.SuppressFinalize(this);
    }
}
