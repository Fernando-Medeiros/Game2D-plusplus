namespace GameEngine.Adapters;

/// <summary>
/// Estrutura responsável por adaptar a janela de renderização de uma biblioteca externa para a janela do jogo.
/// </summary>
public readonly struct ViewportAdapter : IDisposable
{
    private readonly View _view;

    #region Constructor
    public static ViewportAdapter Empty => new();
    public ViewportAdapter(RectAdapter rect) => _view = new(rect);
    public ViewportAdapter(ViewportAdapter viewport) => _view = new(viewport);
    public ViewportAdapter(VectorAdapter center, VectorAdapter size) => _view = new(center, size);
    #endregion

    #region Interface
    public RectAdapter Rect() => new(Position(), Size());
    public VectorAdapter Size() => _view.Size;
    public VectorAdapter Center() => _view.Center;
    public VectorAdapter Position() => _view.Viewport.Position;

    public void SetZoom(float scale) => _view.Zoom(scale);
    public void SetSize(VectorAdapter size) => _view.Size = size;
    public void SetScale(RectAdapter rect) => _view.Viewport = rect;
    public void SetCenter(VectorAdapter vector) => _view.Center = vector;

    public void Reset(RectAdapter rect) => _view.Reset(rect);
    #endregion

    #region SFML Adapter
    public static implicit operator View(ViewportAdapter adapter) => new(adapter.Center(), adapter.Size());

    public static implicit operator ViewportAdapter(View view) => view != null ? new ViewportAdapter(view.Center, view.Size) : ViewportAdapter.Empty;
    #endregion

    #region Override
    public override string ToString() => $"[{nameof(ViewportAdapter)}] Pos::{Position()} Center::{Center()} Size::{Size()}";
    #endregion

    public void Dispose()
    {
        _view.Dispose();

        GC.Collect(GC.GetGeneration(this), GCCollectionMode.Forced);
        GC.SuppressFinalize(this);
    }
}
