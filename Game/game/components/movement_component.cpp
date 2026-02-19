#include "movement_component.hpp"
#include "keyboard_args.hpp"

MovementComponent::MovementComponent(Body2D& linkedEntity) noexcept
	:_linkedEntity{ linkedEntity }
{
}

const EAnchor& MovementComponent::getAnchor() const noexcept
{
	return _anchor;
}

const INode2D& MovementComponent::getAnchorForKey(IEventArgs* keyboardCode) const noexcept
{
	auto keyboard = keyboardCode->toSecurePtr<KeyboardArgs>();

	if (keyboard == nullptr)
		return;

	const EKeyboardKey key = keyboard->getPressed();

	if (key == EKeyboardKey::RIGHT ||
		key == EKeyboardKey::LEFT ||
		key == EKeyboardKey::UP ||
		key == EKeyboardKey::DOWN)
	{
		auto nodePtr = _linkedEntity.getNode().navigate(std::vector{ _anchor });

		return *nodePtr;
	}

	return _linkedEntity.getNode();
}

void MovementComponent::rotateAnchor(IEventArgs* keyboardCode) noexcept
{}

void MovementComponent::moveTo(IEventArgs * keyboardCode) noexcept
{
	//INode2D? node = getAnchorForKey(keyboardCode);

	//if (node is null || node.IsOccupied()) return;

	//_linkedEntity-> Translate(node);

	//EventManager.Invoke(ECore.Sound, node.GetTerrain().ToSound());
}

void MovementComponent::dispose() noexcept
{
}
